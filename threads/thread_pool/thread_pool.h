#pragma once
#include <condition_variable>
#include <functional>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>

class ThreadPool {
    bool done = false;
    std::queue<std::function<void()>> tasks;

    std::mutex m;
    std::condition_variable empty;

    std::vector<std::thread> workers;

public:
    explicit ThreadPool(int numThreads) {
        // start numThreads persistent worker threads
        for (int i = 0; i < numThreads; i++) {
            workers.emplace_back(&ThreadPool::worker, this);
        }
    }

    void submit(std::function<void()> task) {
        // enqueue task and notify a worker
        std::lock_guard lock(m);
        tasks.push(task);
        empty.notify_one();
    }

    ~ThreadPool() {
        // stop accepting new work, drain tasks, join workers
        {
            std::lock_guard lock(m);
            done = true;
            empty.notify_all();
        }

        for (auto& w: workers) {
            w.join();
        }
    }

private:
    // add shared queue, mutex, condition variable, shutdown state,
    // and a collection of worker threads.

    void worker() {
        // wait for work, execute tasks outside queue mutex,
        // and exit once shutdown is requested and queue is empty.
        std::unique_lock<std::mutex> lock(m);
        lock.unlock();

        while (true) {
            lock.lock();
            empty.wait(lock, [&]{ return done || !tasks.empty(); });
            if (done && tasks.empty()) {
                return;
            }

            std::function<void()> task = tasks.front(); tasks.pop();
            lock.unlock();

            task();
        }
    }
};

