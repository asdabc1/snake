//
// Created by asdab on 23.09.2026.
//

#include "Snake.h"

int Snake::moveValueOnMovement(MoveDirection move) {
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

Snake::Snake()  {
    position = std::make_pair(465, 495);
    length = 2;
    moveHistory.push(MoveDirection::forward);
}

void Snake::move(MoveDirection direction, bool lengthen) {
    position.first = moveValueOnMovement(direction);
    moveHistory.push(direction);

    if (!lengthen) {
        position.second = moveValueOnMovement(moveHistory.front());
        moveHistory.pop();
    }
    else
        length++;
}
