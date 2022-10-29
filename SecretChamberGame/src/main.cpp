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
const int BOARDMAX {9};
const int BOARDMIN {0};

void print_board();
int player_move(int *player, int size, char command);
int traps_movement(int (*traps)[3][2]);

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
    //print_board();
    sleep_for(seconds(2));

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

    /*Playter Position*/
    int player[2] = {rand() % 10, rand() % 10};
    board[player[0]][player[1]] = 'P';

    /*Treasure Position*/
    int treasure[2] = {rand() % 10, rand() % 10};
    while (board[treasure[0]][treasure[1]] == 'X' || board[treasure[0]][treasure[1]] == 'P')
    {
        treasure[0] = rand() % 10;
        treasure[1] = rand() % 10;
    }
    board[treasure[0]][treasure[1]] = 'T';


    /*First board Intiali*/
    cout << "Intializing board.....\n"
         << endl;
    sleep_for(seconds(2));
    print_board();

    char command{0};
    int prev_p[2];
    while (true)
    {
        cout << "Enter your move: ";
        cin >> command;
        prev_p[0] = player[0];
        prev_p[1] = player[1];
        player_move(player, 2, command);
        board[prev_p[0]][prev_p[1]] = '.';
        board[player[0]][player[1]] = 'P';
        print_board();
        sleep_for(seconds(2));
        if ((player[0] == treasure[0]) && player[1] == treasure[1])
        {
            cout << "Yipeee, you have found the treasure" << endl;
            cout << "Congratulations" << endl;
            return 1;
        }
        else
        {
            for (int i{0}; i < 3; i++)
            {
                for (int j{0}; j < 2; j++)
                {
                    if (traps[i][0] == player[0] && traps[i][1] == player[1])
                    {
                        cout << "Oh no, you have Stepped into a trap" << endl;
                        cout << "Better luck next time" << endl;
                        return 1;
                    }
                }
            }
        }
        cout << "Trap movement" << endl;
        sleep_for(seconds(2));
        traps_movement(&traps);
        print_board();
        for (int i{0}; i < 3; i++)
        {
            for (int j{0}; j < 2; j++)
            {
                if (traps[i][0] == player[0] && traps[i][1] == player[1])
                {
                    cout << "Oh no, a trap has moved to your location" << endl;
                    cout << "Better luck next time" << endl;
                    return 1;
                }
            }
        }
    }

    return 1;
}

void print_board()
{
    cout << endl;
    for (int i{0}; i < 10; i++)
    {
        cout << board[i] << "\n";
    }
    cout << endl;
}

int player_move(int *player, int size, char command)
{
    switch (command)
    {
    case 'u':
    case 'U':
        if (player[size - 2] == BOARDMIN)
        {
            cout << "Move forfieted, can't go out of the board" << endl;
        }
        else
        {
            --player[size - 2];
        }
        break;

    case 'd':
    case 'D':
        if (player[size - 2] == BOARDMAX)
        {
            cout << "Move forfieted, can't go out of the board" << endl;
        }
        else
        {
            ++player[size - 2];
        }
        break;

    case 'l':
    case 'L':
        if (player[size - 1] == BOARDMIN)
        {
            cout << "Move forfieted, can't go out of the board" << endl;
        }
        else
        {
            --player[size - 1];
        }
        break;

    case 'r':
    case 'R':
        if (player[size - 1] == BOARDMAX)
        {
            cout << "Move forfieted, can't go out of the board" << endl;
        }
        else
        {
            ++player[size - 1];
        }
        break;

    default:
        cout << "Invalid Move entered, move forfieted" << endl;
        break;
    }
    return 1;
}

int traps_movement(int (*traps)[3][2])
{
    int mov[3] = {rand() % 4, rand() % 4, rand() % 4}; //0:up, 1:down, 2:left, 3:right
    int temp{0};

    for (int i{0}; i < 3; i++)
    {
        if (mov[i] == 0)
        {
            temp = (*traps)[i][0];
            //cout << temp << "-" << i<<endl;
            if ((*traps)[i][0] == BOARDMIN && board[temp+1][(*traps)[i][1]] != 'T')
            {
                board[(*traps)[i][0]][(*traps)[i][1]] = '.';
                (*traps)[i][0] = ++temp;
                board[(*traps)[i][0]][(*traps)[i][1]] = 'X';
            }
            else if ((*traps)[i][0] != BOARDMIN && board[temp-1][(*traps)[i][1]] != 'T')
            {
                board[(*traps)[i][0]][(*traps)[i][1]] = '.';
                (*traps)[i][0] = --temp;
                board[(*traps)[i][0]][(*traps)[i][1]] = 'X';
            }
            //cout << temp << "-" << i<<endl;
        }
        else if (mov[i] == 1)
        {
            temp = (*traps)[i][0];
            //cout << temp << "-" << i<<endl;
            if ((*traps)[i][0] == BOARDMAX && board[temp-1][(*traps)[i][1]] != 'T')
            {
                board[(*traps)[i][0]][(*traps)[i][1]] = '.';
                (*traps)[i][0] = --temp;
                board[(*traps)[i][0]][(*traps)[i][1]] = 'X';

            }
            else if ((*traps)[i][0] != BOARDMAX && board[temp+1][(*traps)[i][1]] != 'T')
            {
                board[(*traps)[i][0]][(*traps)[i][1]] = '.';
                (*traps)[i][0] = ++temp;
                board[(*traps)[i][0]][(*traps)[i][1]] = 'X';
            }
            //cout << temp << "-" << i<<endl;
        }
        else if (mov[i] == 2)
        {
            temp = (*traps)[i][1];
            //cout << temp << "-" << i<<endl;
            if ((*traps)[i][1] == BOARDMIN && board[(*traps)[i][0]][temp+1] != 'T')
            {
                board[(*traps)[i][0]][(*traps)[i][1]] = '.';
                (*traps)[i][1] = ++temp;
                board[(*traps)[i][0]][(*traps)[i][1]] = 'X';
            }
            else if ((*traps)[i][1] != BOARDMIN && board[(*traps)[i][0]][temp-1] != 'T')
            {
                board[(*traps)[i][0]][(*traps)[i][1]] = '.';
                (*traps)[i][1] = --temp;
                board[(*traps)[i][0]][(*traps)[i][1]] = 'X';
            }
            //cout << temp << "-" << i<<endl;
        }
        else
        {
            temp = (*traps)[i][1];
            //cout << temp << "-" << i<<endl;
            if ((*traps)[i][1] == BOARDMAX && board[(*traps)[i][0]][temp-1] != 'T')
            {
                board[(*traps)[i][0]][(*traps)[i][1]] = '.';
                (*traps)[i][1] = --temp;
                board[(*traps)[i][0]][(*traps)[i][1]] = 'X';
            }
            else if ((*traps)[i][1] != BOARDMAX && board[(*traps)[i][0]][temp+1] != 'T')
            {   
                board[(*traps)[i][0]][(*traps)[i][1]] = '.';
                (*traps)[i][1] = ++temp;
                board[(*traps)[i][0]][(*traps)[i][1]] = 'X';
            }
            //cout << temp << "-" << i<<endl;
        }
    }
    return 1;
}