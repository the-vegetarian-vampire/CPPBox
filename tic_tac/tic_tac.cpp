#include <iostream>
#include <vector>
#include <string>

// probably want to remove this
using namespace std;

// Function PROTOTYPES [using vectors] pass by reference
void printBoard(const vector<vector<char>> &board);
bool checkWin(const vector<vector<char>> &board, char player);
bool checkDraw(const vector<vector<char>> &board);

int main()
{
    // Initialize the 3x3 board with spaces
    // Data structure is a 2D array (vector of chars)
    vector<vector<char>> board = {{' ', ' ', ' '},
                                  {' ', ' ', ' '},
                                  {' ', ' ', ' '}};

    string playerX, playerO;

    // Get players' names
    cout << "Enter name for Player 1: ";
    cin >> playerX;
    cout << "Enter name for Player 2: ";
    cin >> playerO;

    char player = 'X'; // Start with player 'X'
    string currentPlayer = playerX;

    while (true)
    {
        // Display the board
        printBoard(board);

        // Ask for user input
        int row, col;
        cout << "Player " << currentPlayer << "(" << player << ") ";
        cin >> row >> col;

        // Validate user input
        if (row < 1 || row > 3 || col < 1 || col > 3)
        {
            cout << "-----> Invalid move." << endl;
            cout << "-----> Rows and columns must be between 1 and 3." << endl;
            cout << "-----> Try again..." << endl;

            continue;
        }

        if (board[row - 1][col - 1] != ' ')
        {
            cout << "-----> Already taken." << endl;
            cout << "-----> Try again." << endl;

            continue;
        }

        // Make the move
        board[row - 1][col - 1] = player;

        // Check for win
        if (checkWin(board, player))
        {
            printBoard(board);
            cout << currentPlayer << " wins!" << endl;
            break;
        }

        // Check for draw
        if (checkDraw(board))
        {
            printBoard(board);
            cout << "It's a draw!" << endl;
            break;
        }

        // Switch player
        if (player == 'X')
        {
            player = 'O';
            currentPlayer = playerO;
        }
        else
        {
            player = 'X';
            currentPlayer = playerX;
        }
    }

    return 0;
}

// Function definitions
void printBoard(const vector<vector<char>> &board)
{
    cout << "  1 2 3" << endl;
    for (int i = 0; i < 3; ++i)
    {
        cout << i + 1 << " ";
        for (int j = 0; j < 3; ++j)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool checkWin(const vector<vector<char>> &board, char player)
{
    // Check rows
    for (int i = 0; i < 3; ++i)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
        {
            return true;
        }
    }

    // Check columns
    for (int i = 0; i < 3; ++i)
    {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
        {
            return true;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
    {
        return true;
    }

    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
    {
        return true;
    }

    return false;
}

bool checkDraw(const vector<vector<char>> &board)
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (board[i][j] == ' ')
            {
                return false;
            }
        }
    }
    return true;
}
