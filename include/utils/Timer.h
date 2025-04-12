#ifndef PROJEKT_TIMER_HPP
#define PROJEKT_TIMER_HPP

#include <chrono>

// Class for measuring elapsed time
class Timer {
public:
    Timer(); // Constructor to initialize and prepare to start the timer.
    void reset(); // Method to reset the timer.
    int start(); // Method to start the timer.
    int stop(); // Method to stop the timer.
    int result(); // Method to return the elapsed time in milliseconds.

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime; // Variable to store the start time.
    bool running; // Flag to indicate if the timer is running.
    int elapsedTime; // Variable to store the elapsed time in milliseconds.
};

#endif // PROJEKT_TIMER_HPP