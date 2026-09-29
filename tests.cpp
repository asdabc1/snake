//
// Created by asdab on 28.09.2026.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "Game.h"

using ::testing::Test;

TEST(SnakeTest, checkMovement) {
    Game game;

    game.takeInput('w');
    game.takeInput('d');
    game.takeInput('d');
    game.takeInput('s');
    game.takeInput('a');

    ASSERT_EQ(game.getSnakeInfo(), std::make_pair(getIndex(14, 15), getIndex(14, 16))) << "the snake ended up in an incorrect position";

}

TEST(SnakeTest, checkFruitConsumption) {
    Game game;

    for (int i = 0; i < 6; i++)
        game.takeInput('w');
    for (int i = 0; i < 6; i++)
        game.takeInput('a');

    ASSERT_EQ(game.getSnakeSize(), 3) << "the snake did not enlarge after consuming a fruit";
}

TEST(SnakeTest, checkMapOccupancy) {
    Game game;

    auto map = game.getMap();
    auto filledFields = std::views::iota(0, mapSize) | std::views::filter([&map](int i){return map.test(i);});
    auto count = std::ranges::distance(filledFields);

    ASSERT_EQ(count, game.getSnakeSize()) << "the number of occupied fields on the map does not match snake size";
    ASSERT_EQ(count, 2);

    for (int i = 0; i < 6; i++)
        game.takeInput('w');
    for (int i = 0; i < 6; i++)
        game.takeInput('a');

    map = game.getMap();
    auto filledFieldsAfterCons = std::views::iota(0, mapSize) | std::views::filter([&map](int i){return map.test(i);});
    count = std::ranges::distance(filledFieldsAfterCons);

    ASSERT_EQ(count, game.getSnakeSize()) << "the number of occupied fields on the map does not match snake size";
    ASSERT_EQ(count, 3);
}

class MockSnake : public Game {
public:
    MOCK_METHOD(void, print, (), (override));
};

TEST(SnakeTest, checkPrints) {
    MockSnake game;
    EXPECT_CALL(game, print()).Times(2);

    game.takeInput('w');
    game.takeInput('d');
    game.takeInput('2');
    game.takeInput('p');
    game.takeInput('q');
    game.takeInput('p');

}