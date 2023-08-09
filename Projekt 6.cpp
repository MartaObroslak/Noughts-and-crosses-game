#include <iostream>
using namespace std;

char board[3][3];  

void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard() {
    cout << "  1   2   3" << endl;
    cout << "1 " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "  ---------" << endl;
    cout << "2 " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "  ---------" << endl;
    cout << "3 " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

bool checkWin(char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true; 
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true; 
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true; 
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true; 
    }
    return false;
}

bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false; 
            }
        }
    }
    return true;  
}

int main() {
    initializeBoard();
    char currentPlayer = 'X';

    while (true) {
        printBoard();
        int row, col;
        cout << "Gracz " << currentPlayer << ", podaj wiersz (1-3) i kolumnę (1-3): ";
        cin >> row >> col;

        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
            cout << "Nieprawidłowy ruch. Spróbuj jeszcze raz." << endl;
            continue;
        }

        board[row - 1][col - 1] = currentPlayer;

        if (checkWin(currentPlayer)) {
            printBoard();
            cout << "Gracz " << currentPlayer << " wygrywa!" << endl;
            break;
        }

        if (checkDraw()) {
            printBoard();
            cout << "Remis!" << endl;
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
