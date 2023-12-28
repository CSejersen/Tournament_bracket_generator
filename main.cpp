#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h> 
#include "game.h"

int main(){

  // Vector of all players in tournament
  std::vector<std::string> players;

  // Get user input - all player names
  std::cout << "##############################" << "\n" << std::endl;
  std::cout << " TOURNAMENT BRACKET GENERATOR" << "\n" << std::endl;
  std::cout << "##############################" << "\n" << std::endl;
  std::cout << "Input player names \nPress 'g' to generate bracket\n" << std::endl;
  
  bool input = true;
  int playerNum = 1;
  while(input)
  {
    std::string player;

    std::cout << "Player " << playerNum << ": ";
    std::cin >> player;

    if(player == "g")
    {
      input = false;
      std::cout << "\n \n";
    }
    else 
    {
      players.push_back(player);
    }
      playerNum += 1;
  }

  if(players.size() % 2 == 1){
    players.push_back("NULL_PLAYER");
  }
  
  // calculate number of games in first round
  int num_games = players.size() / 2;
  
  // Vector of all games
  std::vector<Game> games;
  
   /* initialize random seed: */
  srand (time(NULL));

  // generate games
  for(int i = 0; i < num_games; i++){

    int player1 = rand() % players.size();
    std::string player1_name = players[player1]; 
    players.erase(players.begin() + player1);

    int player2 = rand() % players.size();
    std::string player2_name = players[player2]; 
    players.erase(players.begin() + player2);
    

    games.emplace_back(player1_name, player2_name);
  }
  
  for(Game& game : games){
    game.printGame();
  }

  std::cout << "\nGood luck!" << std::endl;
}


