#include "Game.h"

int main() {
    Game game;

    while (game.checkGameInProgress()) {
        game.takeInput(std::cin.get());
    }
}
