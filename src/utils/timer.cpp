#include "utils/timer.hpp"

Timer::Timer() : running(false), elapsedTime(0) {}

void Timer::reset() {
    running = false;
    elapsedTime = 0;
}

int Timer::start() {
    if (!running) {
        startTime = std::chrono::high_resolution_clock::now();
        running = true;
    }
    return 0;
}

int Timer::stop() {
    if (running) {
        auto endTime = std::chrono::high_resolution_clock::now();
        elapsedTime += std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
        running = false;
    }
    return 0;
}

int Timer::result() {
    if (running) {
        auto currentTime = std::chrono::high_resolution_clock::now();
        return elapsedTime + std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - startTime).count();
    }
    return elapsedTime;
}