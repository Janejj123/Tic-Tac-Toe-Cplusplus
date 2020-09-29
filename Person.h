/*
 PIC 10B 2B, Homework 1
 Purpose: Tic-tac-toe game
 Author: Wenjun Jiang
 Date: 10/16/2019
 */

#ifndef Person_h
#define Person_h

#include <iostream>
#include <string>
using namespace std;


class Person{
public:
    Person(const string &name, const char &mark);
    string getName();
    int getScore();
    void increaseScore();
    char getMark(); //X for player 1, 0 for player 2 
        
private:
    string name;
    int score;
    char mark; 

};

#endif 


    
