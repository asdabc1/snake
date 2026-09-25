//
// Created by asdab on 23.09.2026.
//

#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H
#include <bitset>
#include <queue>
#include <iostream>
#include <random>
#include <ranges>

#include "MoveDirection.h"

using Snake = std::pair<int, int>;

constexpr int mapSize = 30 * 30;

inline int getIndex(int row, int col) {
    return 30 * row + col;
}

inline std::pair<int, int> getRowCol(int index) {
    return {index / 30, index % 30};
}

class Game {
    std::bitset<mapSize> map;
    int fruit;

    Snake snakeInfo;
    std::queue<MoveDirection> moveHistory;
    int snakeSize;

    std::mt19937 rng{std::random_device{}()};

    static int newFieldRelativeValue(MoveDirection move);

    bool move(MoveDirection direction);
    void newFruit();

    void endGame();

public:
    Game();
    void print();
    void takeInput(char input);
};


#endif //SNAKE_GAME_H
