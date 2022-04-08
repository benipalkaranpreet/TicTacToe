#include "Board.h"
#include <iostream>
#include <string>

using namespace std;

Board::Board() {
    for (int i = 0; i < 9; ++i) {
        square.emplace_back(i + '0');
    }
 }

void Board::move(int p, char x) { // adds mark x to the p-th sqaure
    square[p] = x;
}
char Board::get(int p) { // returns mark on the p-th sqaure
    return square[p];
}
char Board::check() { 
    if (square[0] == square[4] && square[4] == square[8]) {
        return square[0];
    } else if (square[0] == square[1] && square[1] == square[2]) {
        return square[0];
    } else if (square[3] == square[4] && square[4] == square[5]) {
        return square[3];
    } else if (square[7] == square[6] && square[6] == square[8]) {
        return square[8];
    } else if (square[0] == square[3] && square[3] == square[6]) {
        return square[0];
    } else if (square[1] == square[4] && square[4] == square[7]) {
        return square[1];
    } else if (square[2] == square[5] && square[5] == square[8]) {
        return square[2];
    } else if (square[2] == square[4] && square[4] == square[6]) {
        return square[2];
    }
    return '0';
}
void Board::printB() { 
    cout << " " << square[0] << " | " << square[1] << " | " << square[2] << endl;
    cout << "---+---+---" << endl;
    cout << " " << square[3] << " | " << square[4] << " | " << square[5] << endl;
    cout << "---+---+---" << endl;
    cout << " " << square[6] << " | " << square[7] << " | " << square[8] << endl;
}

char Board::play() {
    int player = 1;
    int p;
    string s;
    char mark = 'N';
    char winner = '0';

    printB();

    for (int t = 0; t < 9; ++t) {
        while (1) {
            cout << "Player " << player << " what square would like to place your piece in?: " << endl;

            getline(cin, s);
            p = s[0] - '0';
            if (p < 0 || p > 8) {
                mark = 'O'; // if non-valid unput make sure it gets ignored

            }
            else {
                mark = get(p);
            }
            if (mark != 'O' && mark != 'X') {
                if (player == 1) {
                    move(p, 'X');
                    player = 2;
                }
                else {
                    move(p, 'O');
                    player = 1;
                }
                break;
            }
            else {
                printB();
                cout << "That was not a valid move" << endl;
            }
        }
        printB();
        winner = check();
        if (winner == 'X') {
            cout << "Player 1 wins!!! It's ok player 2 you tried your best!!" << endl;
            return 'X';
        }
        else if (winner == 'O') {
            cout << "Player 2 wins!!! It's ok player 1 you tried your best!!" << endl;
            return 'O';
        }
    }
    if (winner == '0') {
        cout << "Its a tie, you are both winners <3" << endl;
        return '0';
    }
}
