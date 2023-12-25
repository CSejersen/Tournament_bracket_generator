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
  std::cout << "Input player names, end with 'q'" << std::endl;
  
  bool input = true;
  while(input)
  {
    std::string player;
    std::cin >> player;

    if(player == "q")
    {
      input = false;
      std::cout << "\n \n";
    }
    else 
    {
      players.push_back(player);
    }
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
}



