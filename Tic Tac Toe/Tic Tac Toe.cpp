// Tic Tac Toe.cpp //

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

//int//
int number_of_players;
char player = 'O';
const int size = 9;

//array for board//
int my_array[size] = {};
std::vector <char> board = { '1','2','3','4','5','6','7','8','9' };

char turn = 'X';

bool game_won = false;
bool game_draw = false;

//funtctions//
void set_player() { //sets the players turn.
    if (player == 'O') { //sets player 1s turn
        player = 'X';
        std::cout << "\n Player 1s turn.";
    }
    else { //sets player 2s turn
        player = 'O';
        std::cout << "\n Player 2s turn.";
    }
}

void set_ai() { //sets the players turn.
    if (player == 'O') { //sets player 1s turn
        player = 'X';
        std::cout << "\n Player 1s turn.";
    }
    else { //sets AIs turn
        player = 'O';
        std::cout << "\n Computers turn.";
    }
}

void user_input() { //let's the user input their choice:

    int player_input = 0;

    bool input_exists = false;

    do {
std::cout << " Please select a number 1 - 9: ";
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

if (!input_exists) {
    std::cout << "\n Box is already filled! Try again!\n";
}

    } while (player_input == 0 || player_input > 9 || input_exists == false);
}

void display_board() { //prints the board
    for (int i = 0; i < board.size(); i++) {
        if (i % 3 == 0) {
            std::cout << "\n -------------\n | ";
        }
        std::cout << board[i] << " | ";
    }
    std::cout << "\n -------------";
    std::cout << std::endl;
}


bool check_winner(int p) {

    char is_X_or_O;

    if (p == 1) {
        is_X_or_O = 'X';
    }
    else
        is_X_or_O = 'O';

    if ((board[0] == is_X_or_O) && (board[1] == is_X_or_O) && (board[2] == is_X_or_O)) {
        return true;
    }
    else if ((board[3] == is_X_or_O) && (board[4] == is_X_or_O) && (board[5] == is_X_or_O)) {
        return true;
    }
    else if ((board[6] == is_X_or_O) && (board[7] == is_X_or_O) && (board[8] == is_X_or_O)) {
        return true;
    }
    else if ((board[0] == is_X_or_O) && (board[3] == is_X_or_O) && (board[6] == is_X_or_O)) {
        return true;
    }
    else if ((board[1] == is_X_or_O) && (board[4] == is_X_or_O) && (board[7] == is_X_or_O)) {
        return true;
    }
    else if ((board[2] == is_X_or_O) && (board[5] == is_X_or_O) && (board[8] == is_X_or_O)) {
        return true;
    }
    else if ((board[0] == is_X_or_O) && (board[4] == is_X_or_O) && (board[8] == is_X_or_O)) {
        return true;
    }
    else if ((board[2] == is_X_or_O) && (board[4] == is_X_or_O) && (board[6] == is_X_or_O)) {
        return true;
    }

    //default return
    return false;
}

int calculate_winner() {

    if (check_winner(1)) {
        game_won = true;
        return 1;
    }
    else if (check_winner(2)) {
        game_won = true;
        return 2;
    }
    return 0;
}

void ai_player() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int ai_input = 0;
    bool input_exists = false;
    do {
        ai_input = std::rand() % 9 + 1;
        if (player == 'O') {
            { //If the AI input is valid, the function swaps the number on the board to the users character (X or O depending on the player).
                for (int i = 0; i < board.size(); i++) {
                    if (('0' + ai_input) == board[i]) {
                        board[i] = player;
                        input_exists = true;
                        std::cout << "AI player chose: " << ai_input << std::endl;
                    }
                }
            }
        }
    } while (ai_input == 0 || ai_input > 9 || input_exists == false);
}


int main()
{
    //start screen - Asks the user how many will be playing, and transfers the user to the version of the game they asked for.

    std::cout << "***********Tic-Tac-Toe!***********";

    do {
        std::cout << "\n\n Welcome to Tic-Tac-Toe!" << std::endl;
        display_board();
        std::cout << "\n How many players?\n Type 1 for 1 player, Type 2 for 2 players: ";
        std::cin >> number_of_players;
        if (number_of_players == 0 || number_of_players > 2) {
            std::cout << "\n Invalid input. Try again.\n";
        }
    } while (number_of_players == 0 || number_of_players > 2);


    system("CLS");

    //game screen one player
    if (number_of_players == 1) {
        std::cout << "***********Tic-Tac-Toe!***********\n\n";
        std::cout << "\n Player 1 is [X], AI is [O]\n"; //lets the player know which symbol belongs to them.

        int turn = 0;
        display_board();
        do {
            turn++;
            set_player();
            if (player == 'X') {
                user_input();
            }
            else{
                ai_player();
            }
            
            if (turn > 4) {
                int winner = calculate_winner();
                if (winner == 1) {
                    std::cout << "\n Player 1 is the winner!";
                }
                else if (winner == 2) {
                    std::cout << "\n The computer is the winner!";
                }
                else if (turn == 9) {
                    std::cout << "\n The game has reached a draw. \n Game over";
                    game_draw = true;
                }
            }
            display_board();
        } while (!game_won && !game_draw);
    }
    //game screen two players

    else if (number_of_players == 2) {
        std::cout << "***********Tic-Tac-Toe!***********\n\n";
        std::cout << "\n Player 1 is [X], Player 2 is [O]\n"; //lets the player know which symbol belongs to them.

        int turn = 0;
        display_board();
        do {
            turn++;
            set_player();
            user_input();
            if (turn > 4) {
                int winner = calculate_winner();
                if (winner == 1) {
                    std::cout << "\n Player 1 is the winner!";
                }
                else if (winner == 2) {
                    std::cout << "\n Player 2 is the winner!";
                }
                else if (turn == 9) {
                    std::cout << "\n The game has reached a draw. \n Game over";
                    game_draw = true;
                }
            }
            display_board();
        } while (!game_won && !game_draw);
    }
}


