//
// Created by asdab on 28.09.2026.
//

#include <gtest/gtest.h>

#include "Game.h"

using ::testing::Test;

TEST(SnakeTest, checkMovement) {
    Game game;

    game.takeInput('w');
    game.takeInput('d');
    game.takeInput('d');
    game.takeInput('s');
    game.takeInput('a');

    ASSERT_EQ(game.getSnakeInfo(), std::make_pair(getIndex(14, 15), getIndex(14, 16)));

}

TEST(SnakeTest, checkFruitConsumption) {
    Game game;

    for (int i = 0; i < 6; i++)
        game.takeInput('w');
    for (int i = 0; i < 6; i++)
        game.takeInput('a');

    ASSERT_EQ(game.getSnakeSize(), 3);
}