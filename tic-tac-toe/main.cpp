//  main.cpp
//  tic-tac-toe
//  Created by Caleb Bugnacki on 10/29/22.
//  This program simulates a game of tic-tac-toe between two players 

#include <iostream>
#include<cstdlib>
#include <vector>
#include <iomanip>
using namespace std;

void displayBoard(char board[]) ;
void displayBoardLocations();
void checkAndPlace(int locationChoice,char XorO, char board[]);
int checkWinner(char board[]);


int main() {

    int p1GridLocation{0};
    char ticOrTac = ' ';
    int x {2};

    
    char board[9]= {' ', ' ', ' ', ' ', ' ',' ',' ', ' ',' '}; // array representing the game board
    cout << "Welcome to Tic-Tac-Toe!" << endl ;
    cout << "The integer values used to indicate locations on the Tic-Tac-Toe board are shown below." << endl;
    displayBoardLocations(); // displays the board with the selection numbers for users to define their selected locations to place either an X or an O

    for (int i = 1 ; i <= 9 ; i++){ // iterates until the Tic-Tac-Toe board is filled
        
        /* The if/else statement below is used to alternate turns between player 1 and player 2
           by checking if the turn is even or odd. If the turn is odd, it is player 1's turn else it is player 2's turn. */
        
        if (i % 2 != 0){ // odd = player 1's turn
            cout << "Player 1, enter location on grid to place an X: ";
            cin >> p1GridLocation; // get user input
            ticOrTac = 'X' ;
        }
        else { // even = player 2's turn
            cout << "Player 2, enter location on grid to place an O: ";
            cin >> p1GridLocation; // get user input
            ticOrTac = 'O' ;
        }
        // validates input and places an X or O in a user selected location of board
        checkAndPlace(p1GridLocation - 1, ticOrTac, board);
        
        displayBoard(board); // displays updated board to players
        
        x = checkWinner(board); // checks to see if the game has been won
        if (x == 0){ // 0 is the return value for checkWinner if X's win
            break; // exits loop
        }
        else if (x == 1){ // 1 is the return value for checkWinner if O's win
            break ;
            }
    }
    // checks to see if the game was a draw
    if (x == 2){ // 2 is the return value for checkWinner is neither X nor O won
        cout << "The match is a draw! Better Play Again." << endl;
    }
}
// displays the board and the elements contained in each board location
void displayBoard(char board[]){
    std::cout << "     |     |      \n";
  
    std::cout << "  " << setw(1) << board[0] << "  |  " << setw(1) << board[1] << "  |  " << setw(1) << board[2] << "\n";
  
     std::cout << "_____|_____|_____ \n";
     std::cout << "     |     |      \n";
  
     std::cout << "  " << setw(1) << board[3] << "  |  " << setw(1) << board[4] << "  |  " << setw(1) << board[5] << "\n";
  
     std::cout << "_____|_____|_____ \n";
     std::cout << "     |     |      \n";
  
     std::cout << "  "<< setw(1) << board[6]  << "  |  " << setw(1) << board[7] << "  |  "<< setw(1) << board[8] << "\n";
     std::cout << "     |     |      \n";
  
     std::cout << "\n";
}
// displays locations of spot on the board so that the user may use numbers to select a spot on the board to place an x or an o
void displayBoardLocations(){
    std::cout << "     |     |      \n";
  
    std::cout << "  " << setw(1) << 1 << "  |  " << setw(1) << 2 << "  |  " << setw(1) << 3 << "\n";
  
     std::cout << "_____|_____|_____ \n";
     std::cout << "     |     |      \n";
  
     std::cout << "  " << setw(1) << 4 << "  |  " << setw(1) << 5 << "  |  " << setw(1) << 6 << "\n";
  
     std::cout << "_____|_____|_____ \n";
     std::cout << "     |     |      \n";
  
     std::cout << "  " << setw(1) << 7 << "  |  " << setw(1) << 8 << "  |  " << setw(1) << 9 << "\n";
     std::cout << "     |     |      \n";
  
     std::cout << "\n";
}
// checks that board space is not already occupied and places insert an X or an O into the selected board location
void checkAndPlace(int locationChoice, char XorO , char board[]){
    switch (board[locationChoice]){ // cases validate that the user selected board space is not already occupied by a char 'X','x','O','o'
        case 'X':
            cout << "Location already taken, try again." << endl;
            break;
        case 'O':
            cout << "Location already taken, try again." << endl;
            break;
        case 'o':
            cout << "Location already taken, try again." << endl;
            break;
        case 'x':
            cout << "Location already taken, try again." << endl;
            break;
        default: // board space is unoccupied
            board[locationChoice] = XorO;
            break;
            
    }
}
// cases to check for winner
int checkWinner(char board[]){
    //  checks for all possible winning cases for player 1
    // returns 0 if player 1 wins, 1 if player 2 wins,, and 0 if neither player wins
    if (board[0] == 'X' && board[1] == 'X' && board[2] == 'X'){
        cout << "X's Win!" << endl;
        return 0;
    }
    else if (board[0] == 'X' && board [3] == 'X' && board [6] == 'X'){
        cout << "X's Win!" << endl;
        return 0;
    }
    else if (board[0] == 'X' && board [4] == 'X' && board [8] == 'X'){
        cout << "X's Win!" << endl;
        return 0;
    }
    else if (board[1] == 'X' && board [4] == 'X' && board [7] == 'X'){
        cout << "X's Win!" << endl;
        return 0;
    }
    else if (board[2] == 'X' && board [5] == 'X' && board [8] == 'X'){
        cout << "X's Win!" << endl;
        return 0;
    }
    else if (board[2] == 'X' && board [4] == 'X' && board [6] == 'X'){
        cout << "X's Win!" << endl;
        return 0;
    }
    else if (board[3] == 'X' && board [4] == 'X' && board [5] == 'X'){
        cout << "X's Win" << endl;
        return 0;
    }
    // checks for all possible winning cases for player 2
    else if (board[0] == 'O' && board[1] == 'O' && board[2] == 'O'){
        cout << "O's Win!" << endl;
        return 1;
    }
    else if (board[0] == 'O' && board [3] == 'O' && board [6] == 'O'){
        cout << "O's Win!" << endl;
        return 1;
    }
    else if (board[0] == 'O' && board [4] == 'O' && board [8] == 'O'){
        cout << "O's Win!" << endl;
        return 1;
    }
    else if (board[1] == 'O' && board [4] == 'O' && board [7] == 'O'){
        cout << "O's Win!" << endl;
        return 1;
    }
    else if (board[2] == 'O' && board [5] == 'O' && board [8] == 'O'){
        cout << "O's Win!" << endl;
        return 1;
    }
    else if (board[2] == 'O' && board [4] == 'O' && board [6] == 'O'){
        cout << "O's Win!" << endl;
        return 1;
    }
    else if (board[3] == 'O' && board [4] == 'O' && board [5] == 'O'){
        cout << "O's Win" << endl;
        return 1;
    }
    else // if neither player 1 nor player 2 win, the game is a draw
        return 2;
}

