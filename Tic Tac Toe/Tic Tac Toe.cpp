// Tic Tac Toe.cpp //

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

//int//
int number_of_players;
int player_1;
int player_2;

//funtctions//
int calculateWinner();
int user_input();

bool game_won = false;


int main()
{
    //start screen//
    
    std::cout << "***********Tic-Tac-Toe!***********";

    do {
        std::cout << "\n\n Welcome to Tic-Tac-Toe!\n How many players?\n Type 1 for 1 player, Type 2 for 2 players: ";
        std::cin >> number_of_players;
        if (number_of_players == 0 || number_of_players > 2){
            std::cout << "\n Invalid input. Try again.\n";
        }
    } while (number_of_players == 0 || number_of_players > 2);
    

    system("CLS");

    //game screen//

    std::cout << "***********Tic-Tac-Toe!***********";

    //two player game//

    if (number_of_players == 2){
        do {



        } while (game_won == false);
    }

   
}

