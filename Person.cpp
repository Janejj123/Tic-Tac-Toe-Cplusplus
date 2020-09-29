/*
 PIC 10B 2B, Homework 1
 Purpose: Tic-tac-toe game
 Author: Wenjun Jiang
 Date: 10/16/2019
 */

#include "Person.h"

    Person::Person (const string &Name, const char &Mark): name(Name), mark(Mark), score(0){}


    string Person::getName()
    {
        return name;
    }

    int Person::getScore()
    {
        return score;
    }

    void Person::increaseScore()
    {
        this -> score += 1;
    }

    char Person::getMark()
    {
        return mark; 
    }
