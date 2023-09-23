#include <iostream>
#include <vector>

const int ROWS = 6;
const int COLS = 7;

void printBoard(const std::vector<std::vector<char>>& board) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            std::cout << board[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "-----------------------------\n";
}

bool checkWin(const std::vector<std::vector<char>>& board, char player) {

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS - 3; ++j) {
            if (board[i][j] == player && board[i][j + 1] == player &&
                board[i][j + 2] == player && board[i][j + 3] == player) {
                return true;
            }
        }
    }

    for (int i = 0; i < ROWS - 3; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (board[i][j] == player && board[i + 1][j] == player &&
                board[i + 2][j] == player && board[i + 3][j] == player) {
                return true;
            }
        }
    }

    for (int i = 0; i < ROWS - 3; ++i) {
        for (int j = 0; j < COLS - 3; ++j) {
            if (board[i][j] == player && board[i + 1][j + 1] == player &&
                board[i + 2][j + 2] == player && board[i + 3][j + 3] == player) {
                return true;
            }
        }
    }

    for (int i = 3; i < ROWS; ++i) {
        for (int j = 0; j < COLS - 3; ++j) {
            if (board[i][j] == player && board[i - 1][j + 1] == player &&
                board[i - 2][j + 2] == player && board[i - 3][j + 3] == player) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    std::vector<std::vector<char>> board(ROWS, std::vector<char>(COLS, ' '));
    char currentPlayer = 'X';
    bool gameWon = false;
    int moves = 0;

    while (!gameWon && moves < ROWS * COLS) {
        printBoard(board);

        int column;
        std::cout << "Player " << currentPlayer << ", choose a column (1-7): ";
        std::cin >> column;
        column--;

        if (column < 0 || column >= COLS || board[0][column] != ' ') {
            std::cout << "Invalid move. Try again.\n";
            continue;
        }

        for (int i = ROWS - 1; i >= 0; --i) {
            if (board[i][column] == ' ') {
                board[i][column] = currentPlayer;
                break;
            }
        }

        gameWon = checkWin(board, currentPlayer);
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        moves++;
    }

    printBoard(board);

    if (gameWon) {
        std::cout << "Player " << currentPlayer << " wins!\n";
    } else {
        std::cout << "It's a draw!\n";
    }

    return 0;
}
