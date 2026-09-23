//
// Created by asdab on 23.09.2026.
//

#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H
#include <queue>
#include <utility>

enum class MoveDirection {
    forward,
    left,
    right
};

class Snake {
    std::pair<int, int> position;
    int length;
    std::queue<MoveDirection> moveHistory;
};


#endif //SNAKE_SNAKE_H
