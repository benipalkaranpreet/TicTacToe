/*
Created by Karanpreet Benipal
Made using Visual Studio 2022

This program runs a simple tic tac toe game that takes input
as an integer in the range of 0-8 and places a piece in the 
corresponding sqaure (it will ignore all other input). 

The game ends when a player wins or the board is full. 
Score will be display, you may choose to play another game
*/



#include <iostream>
#include <string>
#include <memory>
#include "Board.h"
using namespace std;


int main() {
    int pOneScore = 0;
    int pTwoScore = 0;

    
    string keepPlaying = "yes";

    while (keepPlaying[0] == 'y' || keepPlaying[0] == 'Y') {
        unique_ptr<Board> b = make_unique<Board>();
        char winner = b->play();
        if (winner == 'X') ++pOneScore;
        else if (winner == 'O') ++pTwoScore;

        cout << "Player1 Score: " << pOneScore << endl;
        cout << "Player2 Score: " << pTwoScore << endl;

        cout << "Would you like to play again? [yes/no]";
        getline(cin, keepPlaying);
        
    }
}
