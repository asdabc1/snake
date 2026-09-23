//
// Created by asdab on 23.09.2026.
//

#include "Game.h"

int Game::newFieldRelativeValue(const MoveDirection move) {
    switch (move) {
        case MoveDirection::forward:
            return -30;

        case MoveDirection::backward:
            return 30;

        case MoveDirection::left:
            return -1;

        case MoveDirection::right:
            return 1;
    }
    return 0;
}

Game::Game() {
    fruit = getIndex(8, 8);
    snakeInfo = std::make_pair(getIndex(14, 14), getIndex(15, 14));
    map[getIndex(14, 14)] = true; map[getIndex(15, 14)] = true;
    snakeSize = 2;
}

void Game::print() {
    for (int i = 0; i < mapSize; i++) {
        if (i % 30 == 0)
            std::cout << std::endl;

        if (map[i])
            std::cout << 'S';
        else if (i == fruit)
            std::cout << 'F';
        else
            std::cout << ' ';
    }
}

bool Game::move(const MoveDirection direction) {
    snakeInfo.first += newFieldRelativeValue(direction);
    map[snakeInfo.first] = true;
    moveHistory.push(direction);

    if (snakeInfo.first == fruit) {
        snakeSize++;
        // and generate a new fruit
    }
    else {
        map[snakeInfo.second] = false;
        snakeInfo.second += newFieldRelativeValue(moveHistory.front());
        moveHistory.pop();
    }

    return true; //will return false if move is invalid - not yet implemented
}
