#include "utils/Timer.h"

// Constructor to initialize the Timer object
Timer::Timer() : running(false), elapsedTime(0) {}

// Method to reset the timer
void Timer::reset() {
    running = false;
    elapsedTime = 0;
}

// Method to start the timer
int Timer::start() {
    if (!running) {
        startTime = std::chrono::high_resolution_clock::now(); // Record the start time
        running = true;
    }
    return 0;
}

// Method to stop the timer
int Timer::stop() {
    if (running) {
        auto endTime = std::chrono::high_resolution_clock::now(); // Record the end time
        elapsedTime += std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count(); // Calculate elapsed time
        running = false;
    }
    return 0;
}

// Method to get the elapsed time
int Timer::result() {
    if (running) {
        auto currentTime = std::chrono::high_resolution_clock::now(); // Get the current time
        return elapsedTime + std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - startTime).count(); // Calculate total elapsed time
    }
    return elapsedTime; // Return the elapsed time if the timer is not running
}