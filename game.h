#pragma once
#include <string>
#include <iostream>

class Game{

public:
  Game(std::string, std::string);

  std::string getPlayer1();
  std::string getPlayer2();
  void printGame();

private:
  std::string player1;
  std::string player2;
};

