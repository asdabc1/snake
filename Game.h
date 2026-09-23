//
// Created by asdab on 23.09.2026.
//

#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H
#include <bitset>

#include "Snake.h"

constexpr int mapSize = 30 * 30;

int getIndex(int row, int col) {
    return 30 * row + col;
}

class Game {
    std::bitset<mapSize> map;
    int fruit;
    Snake snakeInfo;

public:
    void print();
};


#endif //SNAKE_GAME_H
