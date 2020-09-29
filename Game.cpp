/*
 PIC 10B 2B, Homework 1
 Purpose: Tic-tac-toe game
 Author: Wenjun Jiang
 Date: 10/16/2019
 */


#include "Game.h"

    Game::Game (Person *Player1, Person *Player2):player1(Player1), player2(Player2), currentplayer(player1), Mark({{' ',' ',' '}, {' ',' ',' '}, {' ',' ',' '}}) {}
                            //create empty 3x3 vector for game mark 'X' and 'O'



    void Game::print_board() //print board
{
            cout << "    1     2     3" << endl;
        for (int i = 0; i < 3; i++) {
            cout << "       |      |" << endl;
            cout << i + 1 << "  ";
            cout << Mark[i][0] << "   |  ";
            cout << Mark[i][1] << "   |  ";
            cout << Mark[i][2] << endl;
            cout << "       |      |" << endl;
        if (i < 2) {
            cout << "  ------------------" << endl;
        }
    }
}



    bool Game::isInputValid (const int &x, const int &y)
    //check if input is out of board range or if it is already marked
    {
    if (x < 1 || x > 3 || y < 1 || y > 3){
        cout << "please input position in the board range" << endl;
        return false; }
    else if (Mark [x-1][y-1] == 'X' || Mark[x-1][y-1] == 'O'){
        cout << "This position is already marked" << endl;
        return false; }
    else
        return true;
    }



    void Game::switchplayer() //for switching players each turn
    {
    if (currentplayer == player1)
        currentplayer = player2;
    else
        currentplayer = player1;
    }



    bool Game::isFinished()
    //check all possibilities of a player winning or if board is filled
    {
        if((Mark[0][0] == 'X' && Mark[0][1] == 'X' && Mark[0][2] == 'X') ||
       (Mark[1][0] == 'X' && Mark[1][1] == 'X' && Mark[1][2] == 'X') ||
       (Mark[2][0] == 'X' && Mark[2][1] == 'X' && Mark[2][2] == 'X') ||
       (Mark[0][0] == 'X' && Mark[1][0] == 'X' && Mark[2][0] == 'X') ||
       (Mark[0][1] == 'X' && Mark[1][1] == 'X' && Mark[2][1] == 'X') ||
       (Mark[0][2] == 'X' && Mark[1][2] == 'X' && Mark[2][2] == 'X') ||
       (Mark[0][0] == 'X' && Mark[1][1] == 'X' && Mark[2][2] == 'X') ||
       (Mark[2][0] == 'X' && Mark[1][1] == 'X' && Mark[0][2] == 'X'))
    {
        cout << player1 -> getName() << " wins this round" << endl;
        player1 -> increaseScore();
        cout << endl;
        cout << player1 -> getName() << " : " << player1 -> getScore() << endl;
        cout << player2 -> getName() << " : " << player2 -> getScore() << endl;
        return true;}
        
        if((Mark[0][0] == 'O' && Mark[0][1] == 'O' && Mark[0][2] == 'O') ||
       (Mark[1][0] == 'O' && Mark[1][1] == 'O' && Mark[1][2] == 'O') ||
       (Mark[2][0] == 'O' && Mark[2][1] == 'O' && Mark[2][2] == 'O') ||
       (Mark[0][0] == 'O' && Mark[1][0] == 'O' && Mark[2][0] == 'O') ||
       (Mark[0][1] == 'O' && Mark[1][1] == 'O' && Mark[2][1] == 'O') ||
       (Mark[0][2] == 'O' && Mark[1][2] == 'O' && Mark[2][2] == 'O') ||
       (Mark[0][0] == 'O' && Mark[1][1] == 'O' && Mark[2][2] == 'O') ||
       (Mark[2][0] == 'O' && Mark[1][1] == 'O' && Mark[0][2] == 'O'))
    {
        cout << player2 -> getName() << " wins this round" << endl;
        player2 -> increaseScore();
        cout << endl;
        cout << player1 -> getName() << " : " << player1 -> getScore() << endl;
        cout << player2 -> getName() << " : " << player2 -> getScore() << endl;
        return true;}
        
        for (int i = 0; i < 3; i++)
            for (int j = 0; j<3; j++)
                if (Mark[i][j] == ' ')
                    return false;
        
        cout << "The result for this round is a tie!" << endl;
        cout << endl;
        cout << player1 -> getName() << " : " << player1 -> getScore() << endl;
        cout << player2 -> getName() << " : " << player2 -> getScore() << endl;
        return true;
    }





    void Game::play()
    {
        int x,y;
        while (! isFinished()){ //if game is not finished, keep playing!
            while(true){
                cout << currentplayer->getName()<< " " << "(" << currentplayer -> getMark() << ")" << " Please Mark Location" << endl;
                cin >> x >> y;
                while (!cin){ //make sure inputs are two numbers and not a string etc.
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    cout << "Input is not 2 numbers, please input 2 numbers" << endl;
                    cin >> x >> y; //can only exit loop if input are two numbers
                }
                if (isInputValid(x, y) == true)
                    break;
            }
            
            cout << currentplayer -> getName() << " " << "(" << currentplayer -> getMark() << ")" << " Mark Location: " << x << " " << y << endl;
        
            Mark[x-1][y-1] = currentplayer -> getMark();
            //Mark board coordinates with the mark of the current player
            
            print_board(); //print board with the newly marked positions
            
            switchplayer(); //alternate player after every round
        }
    }



