#include <iostream>
#include <vector>
using namespace std;

void printsolution(vector<vector<int>>& board, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool issafe(int row, int col, int n, vector<vector<int>>& board) {
    int i, j;
    i= row;
    j= col;

    // Check the column above
    while(j>=0) {
        if (board[i][j] == 1) {
            return false;
        }
        j--;
    }
    i = row, j = col;

    // Check the upper left diagonal
   while( i >= 0 && j >= 0) {
        if (board[i][j] == 1) {
            return false;
        }
        i--;
        j--;
    }

    i = row, j = col;

    // Check the lower left  diagonal
    while(i < n && j >=0 ) {
        if (board[i][j] == 1) {
            return false;
        }
         i++;
         j--;
    }

    return true;
}

void solve(vector<vector<int>>& board, int col, int n) {
    // Base case
    if (col >= n) {
        printsolution(board, n);
        return;
    }

    for (int row = 0; row < n; row++) {
        if (issafe(row, col, n, board)) {
            board[row][col] = 1;
            solve(board, col + 1, n);
            board[row][col] = 0;
        }
    }
}

int main() {
    int col = 0;
    int n = 4;
    vector<vector<int>> board(n, vector<int>(n, 0));

    solve(board, col, n);
    return 0;
}
