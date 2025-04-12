#ifndef PROJEKT_BOARD_GAME_HPP
#define PROJEKT_BOARD_GAME_HPP

#include <iostream>
#include <cstring>
#include <algorithm>

class BoardGame {
public:
    // Default constructor
    BoardGame() = default;

    // Constructor initializing all fields
    BoardGame(const char* name, const char* publisher, int minPlayers, int maxPlayers, int playTime, int complexity, int fun);

    // Constructor with one argument
    BoardGame(int value);

    // Getters to access private fields
    const char* getName() const;
    const char* getPublisher() const;
    int getMinPlayers() const;
    int getMaxPlayers() const;
    int getPlayTime() const;
    int getComplexity() const;
    int getFun() const;

    // Method to calculate the fun per minute per player
    double calculateFunPerMinutePerPlayer() const;

    // Operator < for comparison
    bool operator<(const BoardGame& other) const;
    bool operator<=(const BoardGame& other) const;
    bool operator>(const BoardGame& other) const;
    friend std::ostream& operator<<(std::ostream& os, const BoardGame& game);
    friend std::istream& operator>>(std::istream& is, BoardGame& game);
    const char* to_string(const BoardGame& game);

private:
    // Name of the board game
    char name[50];

    // Publisher of the board game
    char publisher[50];

    // Minimum number of players
    int minPlayers;

    // Maximum number of players
    int maxPlayers;

    // Play time in minutes
    int playTime;

    // Complexity level of the game
    int complexity;

    // Fun level of the game
    int fun;
};

#endif // PROJEKT_BOARD_GAME_HPP