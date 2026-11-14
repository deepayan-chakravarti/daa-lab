#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

bool isSafe(int board[20][20], int row, int col, int n) {
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }
    
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    
    return true;
}

bool solveNQueens(int board[20][20], int row, int n) {
    if (row == n) {
        return true;
    }
    
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 1;
            
            if (solveNQueens(board, row + 1, n)) {
                return true;
            }
            
            board[row][col] = 0;
        }
    }
    return false;
}

int main() {
    cout<<"Deepayan Chakravarti"<<endl;
    cout<<"04714802724"<<endl;
    int n;
    
    cout << "Enter the number of queens: ";
    cin >> n;
    
    if (n <= 0 || n > 20) {
        cout << "Please enter a positive number (up to 20).\n";
        return 0;
    }
    
    int board[20][20] = {0};
    
    auto start = high_resolution_clock::now();
    
    if (solveNQueens(board, 0, n)) {
        cout << "\nSolution:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << board[i][j] << " ";
            }
            cout << '\n';
        }
    } else {
        cout << "No solution exists for " << n << " queens.\n";
    }
    
    auto stop = high_resolution_clock::now();
    double ms = duration<double, milli>(stop - start).count();
    
    cout << "\nExecution time: " << ms << " ms\n";
    
    return 0;
}