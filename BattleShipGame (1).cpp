#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

const int BOARD_SIZE = 7;

void printBoard(vector<vector<char>> &board, bool showShips) {
    cout << "  ";
    for (int i = 0; i < BOARD_SIZE; i++) {
        cout << i << " ";
    }
    cout << endl;
    for (int i = 0; i < BOARD_SIZE; i++) {
        cout << i << " ";
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (!showShips && board[i][j] == 'S') {
                cout << "~ ";
            } else {
                cout << board[i][j] << " ";
            }
        }
        cout << endl;
    }
}

void placeShip(vector<vector<char>> &board, int length) {
    bool placed = false;
    while (!placed) {
        int row = rand() % BOARD_SIZE;
        int col = rand() % BOARD_SIZE;
        bool horizontal = rand() % 2;

        bool canPlace = true;
        for (int i = 0; i < length; i++) {
            int r = row + (horizontal ? 0 : i);
            int c = col + (horizontal ? i : 0);

            if (r >= BOARD_SIZE || c >= BOARD_SIZE || board[r][c] != '~') {
                canPlace = false;
                break;
            }
        }

        if (canPlace) {
            for (int i = 0; i < length; i++) {
                int r = row + (horizontal ? 0 : i);
                int c = col + (horizontal ? i : 0);
                board[r][c] = 'S';
            }
            placed = true;
        }
    }
}

void placeAllShips(vector<vector<char>> &board) {
    placeShip(board, 3);
    placeShip(board, 2);
    placeShip(board, 2);
    placeShip(board, 1);
    placeShip(board, 1);
    placeShip(board, 1);
    placeShip(board, 1);
}

bool isHit(vector<vector<char>> &board, int row, int col) {
    return board[row][col] == 'S';
}

bool allShipsSunk(vector<vector<char>> &board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 'S') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    srand(time(0));
    vector<vector<char>> board(BOARD_SIZE, vector<char>(BOARD_SIZE, '~'));
    vector<vector<char>> playerView(BOARD_SIZE, vector<char>(BOARD_SIZE, '~'));

    placeAllShips(board);

    int shots = 0;
    bool gameWon = false;

    while (!gameWon) {
        cout << "Player Board:\n";
        printBoard(playerView, false);

        int row, col;
        cout << "Enter row and column to shoot: ";
        cin >> row >> col;

        if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
            cout << "Out of bounds! Try again.\n";
            continue;
        }

        if (playerView[row][col] != '~') {
            cout << "You already shot here! Try again.\n";
            continue;
        }

        shots++;

        if (isHit(board, row, col)) {
            cout << "Hit!\n";
            playerView[row][col] = 'X';
            board[row][col] = '~';
        } else {
            cout << "Miss!\n";
            playerView[row][col] = 'O';
        }

        gameWon = allShipsSunk(board);
    }

    cout << "Congratulations! You sank all the ships in " << shots << " shots.\n";
    return 0;
}
