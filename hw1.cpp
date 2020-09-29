/*
 PIC 10B 2B, Homework 1
 Purpose: Tic-tac-toe game
 Author: Wenjun Jiang
 Date: 10/16/2019
 */

#include "Person.h"
#include "Game.h"

int main()
{
    int NumberOfGames;
    cout << "Please input the number of games you would like to play:";
    cin >> NumberOfGames;
    while(!cin){ //make sure input is a number
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "please input a number!" << endl;
        cin >> NumberOfGames;}
    
    string playerName;
   
    cout << "Please input first player name:";
    cin >> playerName;
    Person *player1 = new Person(playerName, 'X');
    
    cout << "Please input second player name:";
    cin >> playerName;
    Person *player2 = new Person(playerName, 'O');
    
    int i;
    for (i=NumberOfGames; i>0; i--){ //play for the number of games entered
        Game *TicTac =new Game(player1, player2);
        
        cout << endl;
        cout << "Number of games: " << i << endl;
        cout << "Player 1 Name = " << player1 -> getName() << endl;
        cout << "Player 2 Name = " << player2 -> getName() << endl;
        cout << "    Tic Tac Toe" << endl;
        cout << player1 -> getName() << " (X) " << player2 -> getName() << " (O) " << endl;
        
        TicTac -> print_board(); //print empty board first
        TicTac -> play();
        
        delete TicTac; //free up memory
    }
    
        cout << endl;
    if (player1 -> getScore() > player2 -> getScore()){
        cout << "Congratulations " << player1 -> getName() << " you won the entire game!" << endl;
    }
    else if (player1 -> getScore() < player2 -> getScore()){
        cout << "Congratulations " << player2 -> getName() << " you won the entire game!" << endl;
    }
    else{
        cout << "The final result is a tie!" << endl;
    }
    
    delete player1; //free up memory
    delete player2;
    
    system("pause");
    return 0;
}
