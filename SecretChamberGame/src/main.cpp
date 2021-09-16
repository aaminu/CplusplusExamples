#include <iostream>
#include <array>
#include <string>
#include <chrono>
#include <thread>
#include <stdlib.h>
#include <time.h>

using namespace std;
using namespace std::chrono;
using namespace std::this_thread;

static array<string, 10> board;
void print_board();

int main()
{
    //Instructions
    cout << "Welcome to the Secrete Chamber Game"
         << "\n";
    cout << "You are letter P, and The Treasure is letter T"
         << "\n";
    cout << "Use U,D,L,R for movements, (Case Insensitive)"
         << "\n";
    cout << "And Oh, avoid the Traps X"
         << "\n"
         << endl;

    //intializee a 10x10 board array
    for (int i{0}; i < 10; i++)
    {
        board[i] = "..........";
    }
    print_board();
    

    /*3 Trap postions */
    int traps[3][2];
    srand(time(NULL));
    for (int i{0}; i < 3; i++)
    {
        for (int j{0}; j < 2; j++)
        {
            traps[i][j] = rand() % 10;
        }
        board[traps[i][0]][traps[i][1]] = 'X';
    }

    /*Treasure Position*/
    int treasure[2] = {rand() % 10, rand() % 10};
    board[treasure[0]][treasure[1]] = 'T';

    /*Playter Position*/
    int player[2] = {rand() % 10, rand() % 10};
    board[player[0]][player[1]] = 'P';


    /*First board Intiali*/
    cout << "Intializing board.....\n" << endl;
    sleep_for(seconds(2));
    print_board();



    return 1;
}


void print_board()
{
    for (int i{0}; i < 10; i++)
    {
        cout << board[i] << "\n";
    }
    cout << endl;
}
