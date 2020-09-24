// Tic Tac Toe.cpp //

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>

//int//
int number_of_players;
char player = 'O';
const int size = 9;

//array for board//
int my_array[size] = {};
std::vector <char> board = { '1','2','3','4','5','6','7','8','9' };

char turn = 'X';

bool game_won = false;

//funtctions//
int calculateWinner();

void set_player() { //sets the players turn.
    if (player == 'O') { //sets player 1s turn
        player = 'X';
        std::cout << "\n Player 1s turn. Please select a number 1-9: ";
    }
    else { //sets player 2s turn
        player = 'O';
        std::cout << "\n Player 2s turn. Please select a number 1-9: ";
    }
}

void user_input() { //let's the user input their choice:

    int player_input = 0;

    bool input_exists = false;

    do {
        
        std::cin >> player_input;

        if (player_input == 0 || player_input > 9) { //Checks if user input is valid or not.
            std::cout << "\n Invalid input, try again.";
        }

        else { //If user input is valid, the function swaps the number on the board to the users character (X or O depending on the player).
            for (int i = 0; i < board.size(); i++) {
                if (('0' + player_input) == board[i]) {
                    board[i] = player;
                    input_exists = true;
                }
            }
            
        }
        if (!input_exists){
            std::cout << "\n Invalid input, try again. \n Type a new choice here: ";
        }

    } while (player_input == 0 || player_input > 9 || input_exists == false);


}

void display_board() { //prints the board
    std::cout << "Player 1 is [X], Player 2 is [O]\n"; //lets the player know which symbol belongs to them.
    for (int i = 0; i < board.size(); i++) {
        if (i % 3 == 0) {
            std::cout << "\n-------------\n| ";
        }
        std::cout << board[i] << " | ";
    }
    std::cout << "\n-------------";
    std::cout << std::endl;
}

int main()
{
    //start screen - Asks the user how many will be playing, and transfers the user to the version of the game they asked for.

    std::cout << "***********Tic-Tac-Toe!***********";

    do {
        std::cout << "\n\n Welcome to Tic-Tac-Toe!\n How many players?\n Type 1 for 1 player, Type 2 for 2 players: ";
        std::cin >> number_of_players;
        if (number_of_players == 0 || number_of_players > 2) {
            std::cout << "\n Invalid input. Try again.\n";
        }
    } while (number_of_players == 0 || number_of_players > 2);


    system("CLS");

    //game screen//

    std::cout << "***********Tic-Tac-Toe!***********\n\n";
    
    display_board();
    set_player();
    user_input();
    display_board();
    set_player();
    user_input();
    display_board();
    set_player();
    user_input();
    display_board();


}

    //two player game//

//    if (number_of_players == 2){
//        do {
//
//            display_board();
//
//        } while (game_won == false);
//    }
//
//   
//}

