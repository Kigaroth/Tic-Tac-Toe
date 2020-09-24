// Tic Tac Toe.cpp //

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int number_of_players = 0;
int check_win;


int main()
{
    std::cout << "***********Tic-Tac-Toe!***********";

    do {
        std::cout << "\n\n Welcome to Tic-Tac-Toe!\n How many players?\n Type 1 for 1 player, Type 2 for 2 players: ";
        std::cin >> number_of_players;
    } while (number_of_players == 0 || number_of_players > 2);

}
