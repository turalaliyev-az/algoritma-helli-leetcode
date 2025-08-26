//n-queens cikti sayisi
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
using namespace std;    
class Solution {
public:
        int totalNQueens(int n) {
            vector<string> board(n, string(n, '.'));
            return backtrack(board, 0, n);
        }
    
    private:
        int backtrack(vector<string>& board, int row, int n) {
            if (row == n) return 1;
            int count = 0;
            for (int col = 0; col < n; ++col) {
                if (isValid(board, row, col, n)) {
                    board[row][col] = 'Q';
                    count += backtrack(board, row + 1, n);
                    board[row][col] = '.';
                }
            }
            return count;
        }
    
        bool isValid(vector<string>& board, int row, int col, int n) {
            for (int i = 0; i < row; ++i) {
                if (board[i][col] == 'Q') return false;
            }
            for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
                if (board[i][j] == 'Q') return false;
            }
            for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j) {
                if (board[i][j] == 'Q') return false;
            }
            return true;
        }

};
int main() {
    Solution sol;
    int n = 4;
    int result = sol.totalNQueens(n);
    cout << "Total distinct solutions for " << n << "-Queens: " << result << endl;
    return 0;
}