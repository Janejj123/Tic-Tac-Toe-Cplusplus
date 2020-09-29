/*
 PIC 10B 2B, Homework 1
 Purpose: Tic-tac-toe game
 Author: Wenjun Jiang
 Date: 10/16/2019
 */

#ifndef Game_h
#define Game_h

#include "Person.h"
#include <vector>

class Game {
    
public:
    Game(Person *player1, Person *player2); 
    void print_board();
    bool isInputValid (const int &x, const int &y);
    void switchplayer();
    bool isFinished();
    void play();
        
private:
    Person *player1; 
    Person *player2;
    vector<vector<char>> Mark;
    Person *currentplayer;
        
    
};

#endif
