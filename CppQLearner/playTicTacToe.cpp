#include <memory>
#include <iostream>

#include "QLearner.h"
#include "TicTacToe.h"

int main() {
  auto ticTacToeGame = TicTacToe();
  auto human = std::make_shared<HumanPlayer<TicTacToe, GameState, Action>>(ticTacToeGame);

  double epsilon = 0.3;
  double alpha = 0.9;
  double gamma = 0.9;

  auto ticTacToeAI = std::make_shared<AI<TicTacToe, GameState, Action, QPair, QLearnerMap>>(ticTacToeGame, epsilon, alpha, gamma);
  ticTacToeAI->learnGames(500000);

  std::vector<std::shared_ptr<Player<GameState, Action>>> players {human, ticTacToeAI};
  while (true) {
    ticTacToeGame.playGame(players);
    std::cout << "\n\n\n";
  }
}
