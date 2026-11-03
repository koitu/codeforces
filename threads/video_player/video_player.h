#include <bits/stdc++.h>
#include <chrono>
#include <thread>

class Frame;

std::optional<Frame> Read();
void Render(const Frame& frame);

using namespace std;

// auto nextTime = steady_clock::now() + 40ms;
// std::this_thread::sleep_until(nextTime);

// 25 fps is a target for the max rate, but if reading or rendering get too slow then actual fps can be lower

class VideoPlayer {
    bool done = false;
    int cur_frames = 0;
    int max_frames = 8;
    queue<Frame> buffer;

    mutex m;
    condition_variable empty;
    condition_variable full;

    void producer() {
        while (true) {
            unique_lock lock(m);
            full.wait(lock, [&]{ return cur_frames < max_frames; });

            // fine to unlock since only one producer thread and consumer can only decrease our buffer
            lock.unlock();

            std::optional<Frame> cur = Read();

            lock.lock();
            if (cur == std::nullopt) {
                empty.notify_one();
                done = true;
                return;
            }

            buffer.push(move(*cur));
            cur_frames++;
            empty.notify_one();
        }
    }

    void consumer() {
        while (true) {
            unique_lock lock(m);
            empty.wait(lock, [&]{ return done || cur_frames > 0; });
            if (done && cur_frames == 0) {
                return;
            }

            Frame f = move(buffer.front()); buffer.pop();
            cur_frames--;
            full.notify_one();

            lock.unlock();

            auto nextTime = chrono::steady_clock::now() + chrono::milliseconds(40);
            Render(f);
            std::this_thread::sleep_until(nextTime);
        }
    }


public:
    VideoPlayer() {}

    void play() {
        thread p(&VideoPlayer::producer, this);
        thread c(&VideoPlayer::consumer, this);

        p.join();
        c.join();
    }
};

int main() {
    VideoPlayer vp;
    vp.play();
}

