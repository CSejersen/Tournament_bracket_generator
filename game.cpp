#include "game.h"
#include <string_view>

Game::Game(std::string player1, std::string player2){
  this->player1 = player1;
  this->player2 = player2;
}

std::string Game::getPlayer1(){
  return player1;
}

std::string Game::getPlayer2(){
  return player2;
}

void Game::printGame(){
  std::cout << player1 << " VS " << player2 << "\n" << std::endl;
}
