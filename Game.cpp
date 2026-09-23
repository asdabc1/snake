//
// Created by asdab on 23.09.2026.
//

#include "Game.h"

int Game::newFieldRelativeValue(MoveDirection move) {
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
    fruit = getIndex(13, 13);
    snakeInfo = std::make_pair(getIndex(15, 15), getIndex(16, 15));
    map[getIndex(15, 15)] = true; map[getIndex(16, 15)] = true;
}

void Game::print() {

}

bool Game::move(MoveDirection direction) {
    snakeInfo.first += newFieldRelativeValue(direction);
    moveHistory.push(direction);

    if (snakeInfo.first == fruit) {
        snakeSize++;
        // and generate a new fruit
    }
    else {
        snakeInfo.second += newFieldRelativeValue(moveHistory.front());
        moveHistory.pop();
    }
}
