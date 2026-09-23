//
// Created by asdab on 23.09.2026.
//

#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H
#include <bitset>
#include <queue>
#include <iostream>

#include "MoveDirection.h"

using Snake = std::pair<int, int>;

constexpr int mapSize = 30 * 30;

inline int getIndex(int row, int col) {
    return 30 * row + col;
}

class Game {
    std::bitset<mapSize> map;
    int fruit;

    Snake snakeInfo;
    std::queue<MoveDirection> moveHistory;
    int snakeSize;

    static int newFieldRelativeValue(MoveDirection move);

public:
    Game();
    void print();
    bool move(MoveDirection direction);
};


#endif //SNAKE_GAME_H
