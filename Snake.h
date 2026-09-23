//
// Created by asdab on 23.09.2026.
//

#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H
#include <queue>
#include <utility>

enum class MoveDirection {
    forward,
    backward,
    left,
    right
};

class Snake {
    std::pair<int, int> position;
    int length;
    std::queue<MoveDirection> moveHistory;

    static int moveValueOnMovement(MoveDirection move);

public:
    Snake();
    void move(MoveDirection direction, bool lengthen = false);
};


#endif //SNAKE_SNAKE_H
