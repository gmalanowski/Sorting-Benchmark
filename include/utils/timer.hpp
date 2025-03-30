#ifndef PROJEKT_TIMER_HPP
#define PROJEKT_TIMER_HPP

#include <chrono>

class Timer {
public:
    Timer(); // Initialize and prepare to start.
    void reset(); // Reset timer.
    int start(); // Start timer.
    int stop(); // Stop timer.
    int result(); // Return elapsed time [ms].

private:
    // Everything else you need, both fields and methods.
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
    bool running;
    int elapsedTime; // in milliseconds
};

#endif // PROJEKT_TIMER_HPP