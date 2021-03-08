/* Tic Tac Toe*/

#include <iostream>
#include <vector>
#include <algorithm>


#define c (char)

void displayGame (int gb[3][3]);
char handlePlayerTurn (int gameBoard[3][3], std::vector<int> &alreadyChosen, int &turn);
int checkForWinner (int gb[3][3], int currentPick, int numTurns);

int main ()
{
    char currentPick;
    int turn = 0; // Game states - 0: player1, 1: player2.
    int numTurns = 0;

    // An empty vector which will store values already chosen by players.
    std::vector<int> alreadyChosen;

    // Initialize game board.
    int gameBoard[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'},
    };

    // Loop for input until a winner is declared.
    while (true)
    {
        displayGame(gameBoard);
        currentPick = handlePlayerTurn(gameBoard, alreadyChosen, turn);
        
        // Print contents of vector for debugging.
        // for (int i = 0; i < alreadyChosen.size(); i++)
        // {
        //     std::cout << c alreadyChosen[i] << " ";
        // }
        // std::cout << std::endl;

        alreadyChosen.push_back(currentPick);

        // Iterate through each square tile.
        for (int i = 0; i < 3; i++) // For each row.
        {
            for (int j = 0; j < 3; j++) // For each column.
            {
                if (c currentPick == c gameBoard[i][j])
                {
                    gameBoard[i][j] = (turn == 0) ? 'x' : 'o';
                }
            }
        }

        if (checkForWinner(gameBoard, currentPick, turn) == 1)
        {
            displayGame(gameBoard);
            std::cout << "Game draw!" << std::endl;
            break;
        }
        else if (checkForWinner(gameBoard, currentPick, turn) == 2)
        {
            // Congratulate the winner.
            displayGame(gameBoard);
            if (turn == 0)
            {
                std::cout << "\nPlayer 1 wins!" << std::endl;
            }
            else
            {
                std::cout << "\nPlayer 2 wins!" << std::endl;
            }
            break;
        }
    }

    return 0;
}

void displayGame (int gb[3][3])
{
    std::cout << "\nTIC TAC TOE" << std::endl;
    std::cout << c gb[0][0] << " | " << c gb[0][1] << " | " << c gb[0][2] << "\n"
              << "--|---|---" << "\n"
              << c gb[1][0] << " | " << c gb[1][1] << " | " << c gb[1][2] << "\n"
              << "--|---|---" << "\n"
              << c gb[2][0] << " | " << c gb[2][1] << " | " << c gb[2][2] << std::endl;
}

// Return chosen player square.
char handlePlayerTurn (int gameBoard[3][3], std::vector<int> &alreadyChosen, int &turn)
{
    char currentPick;
    bool pickIsInChosen = false;

    do
    {
        if (pickIsInChosen)
        {
            std::cout << "Square has already been chosen!\n" << std::endl;
            displayGame(gameBoard);
        }

        if (turn == 0)
        {
            // Player 1's turn.
            std::cout << "Player 1, pick a number (1 - 9)." << std::endl;
            std::cin >> currentPick;

        }
        else
        {
            // Player 2's turn.
            std::cout << "Player 2, pick a number (1 - 9)." << std::endl;
            std::cin >> currentPick;

        }

        // Trying to figure out how to only accept 1 character and reject anything else...
        // while (!(std::cin >> currentPick) || ((currentPick < 0) && (currentPick > 9)))
        // {
        //     std::cout << "Invalid input" << std::endl;
        //     std::cin.clear();
        //     std::cin.ignore(123, '\n');

        //     if ( (currentPick < 0) && (currentPick > 9) )
        //     {
        //     std::cout << "Invalid pick!" << std::endl;
        //     continue;
        //     }
        // }

        pickIsInChosen = true;
    }
    while (std::count(alreadyChosen.begin(), alreadyChosen.end(), currentPick));

    turn = (turn == 0) ? 1 : 0;

    return currentPick;
}

// Crappy algorithm that checks if a three-in-a-row happens.
// Return 0: no win, 1: draw, 2: win.
int checkForWinner (int gb[3][3], int currentPick, int numTurns)
{
    char mark = 'x';

    for (int i = 0; i < 3; i++) // For each row.
    {
        for (int j = 0; j < 3; j++) // For each column.
        {
            for (int m = 0; m < 2; m++) // For each player.
            {
                // All possible winning conditions. There's probably a smarter algorithm
                // to do this instead of multiple if-else statements, but I dunno.
                if ( (c mark == c gb[0][0]) && (c mark == c gb[0][1]) && (c mark == c gb[0][2]) )
                {
                    return 2;
                }
                else if ( (c mark == c gb[1][0]) && (c mark == c gb[1][1]) && (c mark == c gb[1][2]) )
                {
                    return 2;
                }
                else if ( (c mark == c gb[2][0]) && (c mark == c gb[2][1]) && (c mark == c gb[2][2]) )
                {
                    return 2;
                }
                else if ( (c mark == c gb[0][0]) && (c mark == c gb[1][0]) && (c mark == c gb[2][0]) )
                {
                    return 2;
                }
                else if ( (c mark == c gb[0][1]) && (c mark == c gb[1][1]) && (c mark == c gb[2][1]) )
                {
                    return 2;
                }
                else if ( (c mark == c gb[0][2]) && (c mark == c gb[1][2]) && (c mark == c gb[2][2]) )
                {
                    return 2;
                }
                else if ( (c mark == c gb[0][0]) && (c mark == c gb[1][1]) && (c mark == c gb[2][2]) )
                {
                    return 2;
                }
                else if ( (c mark == c gb[2][0]) && (c mark == c gb[1][1]) && (c mark == c gb[0][2]) )
                {
                    return 2;
                }
            }
            mark = 'o';
        }
    }

    if (numTurns == 9)
    {
        return 1;
    }

    return 0;
}
