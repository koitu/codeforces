// Build and run:
// g++ -std=c++17 -O1 -g -Wall -Wextra -pthread thread_pool_test.cpp -o test && ./test
// Optional (if supported): add -fsanitize=thread to find data races.
// Put your own ThreadPool class into thread_pool.h to test it.
#include "thread_pool.h"
#include <atomic>
#include <cassert>
#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

int main() {
    constexpr int N = 2000;
    std::vector<std::atomic<int>> hits(N);
    for (auto& x : hits) x.store(0);
    std::atomic<int> count{0};

    {
        ThreadPool pool(4);
        for (int i = 0; i < N; ++i) {
            pool.submit([&, i] {
                ++hits[i];
                ++count;
            });
        }
        // The destructor must finish all pending tasks before returning.
    }

    assert(count.load() == N && "Some tasks were lost during shutdown");
    for (int i = 0; i < N; ++i) {
        assert(hits[i].load() == 1 && "A task was lost or executed twice");
    }
    std::cout << "PASS: 2000 tasks executed exactly once, with shutdown draining\n";

    std::atomic<int> finished{0};
    {
        ThreadPool pool(2);
        for (int i = 0; i < 40; ++i) {
            pool.submit([&] {
                std::this_thread::sleep_for(std::chrono::milliseconds(2));
                ++finished;
            });
        }
    }
    assert(finished.load() == 40);
    std::cout << "PASS: destructor waits for slow queued tasks\n";
    std::cout << "All tests passed. (Tests cannot prove absence of concurrency bugs.)\n";
}

