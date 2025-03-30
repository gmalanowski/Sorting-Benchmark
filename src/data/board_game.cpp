#include "../../include/data/board_game.hpp"
#include <cstring>

// Constructor initializing all fields
BoardGame::BoardGame(const char* name, const char* publisher, int minPlayers, int maxPlayers, int playTime, int complexity, int fun)
        : minPlayers(minPlayers), maxPlayers(maxPlayers), playTime(playTime), complexity(complexity), fun(fun) {
    std::strncpy(this->name, name, sizeof(this->name) - 1);
    this->name[sizeof(this->name) - 1] = '\0';
    std::strncpy(this->publisher, publisher, sizeof(this->publisher) - 1);
    this->publisher[sizeof(this->publisher) - 1] = '\0';
}

// Constructor with one argument
BoardGame::BoardGame(int value)
        : minPlayers(value % 10 + 1), maxPlayers(value % 10 + 1), playTime(value % 120 + 1), complexity(value % 5 + 1), fun(value % 10 + 1) {
    std::snprintf(this->name, sizeof(this->name), "Game%d", value);
    std::snprintf(this->publisher, sizeof(this->publisher), "Publisher%d", value);
}

// Getters to access private fields
const char* BoardGame::getName() const {
    return name;
}

const char* BoardGame::getPublisher() const {
    return publisher;
}

int BoardGame::getMinPlayers() const {
    return minPlayers;
}

int BoardGame::getMaxPlayers() const {
    return maxPlayers;
}

int BoardGame::getPlayTime() const {
    return playTime;
}

int BoardGame::getComplexity() const {
    return complexity;
}

int BoardGame::getFun() const {
    return fun;
}

// Method to calculate the fun per minute per player
double BoardGame::calculateFunPerMinutePerPlayer() const {
    return static_cast<double>(fun) / playTime / ((minPlayers + maxPlayers) / 2.0);
}

// Operator < for comparison
bool BoardGame::operator<(const BoardGame& other) const {
    return fun < other.fun; // Example comparison based on fun level
}

std::ostream& operator<<(std::ostream& os, const BoardGame& game) {
    os << "Name: " << game.name << ", Publisher: " << game.publisher
       << ", Min Players: " << game.minPlayers << ", Max Players: " << game.maxPlayers
       << ", Play Time: " << game.playTime << ", Complexity: " << game.complexity
       << ", Fun: " << game.fun;
    return os;
}

std::istream& operator>>(std::istream& is, BoardGame& game) {
    is >> game.name >> game.publisher >> game.minPlayers >> game.maxPlayers
       >> game.playTime >> game.complexity >> game.fun;
    return is;
}

std::string to_string(const BoardGame& game) {
    std::ostringstream oss;
    oss << "Name: " << game.getName() << ", Publisher: " << game.getPublisher()
        << ", Min Players: " << game.getMinPlayers() << ", Max Players: " << game.getMaxPlayers()
        << ", Play Time: " << game.getPlayTime() << ", Complexity: " << game.getComplexity()
        << ", Fun: " << game.getFun();
    return oss.str();
}