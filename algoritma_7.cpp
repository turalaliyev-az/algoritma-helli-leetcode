// Sudoku Solver
#include <bits/stdc++.h>
using namespace std;    

class Solution {
public:

// BACKTRACKING APPROACH FOR SUDOKU
/*
        void solveSudoku(vector<vector<char>>& board) {
           // Row, Column, and Box trackers
            vector<vector<bool>> row(9, vector<bool>(9, false));
            vector<vector<bool>> col(9, vector<bool>(9, false));
            vector<vector<bool>> box(9, vector<bool>(9, false));
            
            // Initialize trackers based on the initial board state
            for(int i = 0; i < 9; i++){
                for(int j = 0; j < 9; j++){
                    if(board[i][j] != '.'){
                        int num = board[i][j] - '1'; // Convert char to int (0-8)
                        row[i][num] = true;
                        col[j][num] = true;
                        box[(i / 3) * 3 + (j / 3)][num] = true;
                    }
                }
            }
            
            solve(board, row, col, box, 0, 0);  
        }
    
    private:
        bool solve(vector<vector<char>>& board, vector<vector<bool>>& row, vector<vector<bool>>& col, vector<vector<bool>>& box, int i, int j) {
            if (i == 9) return true;
            if (j == 9) return solve(board, row, col, box, i + 1, 0);
            if (board[i][j] != '.') return solve(board, row, col, box, i, j + 1);
    
            for (int num = 0; num < 9; num++) {
                int boxIdx = (i / 3) * 3 + (j / 3);
                if (!row[i][num] && !col[j][num] && !box[boxIdx][num]) {
                    board[i][j] = num + '1';
                    row[i][num] = col[j][num] = box[boxIdx][num] = true;
                    if (solve(board, row, col, box, i, j + 1)) return true;
                    board[i][j] = '.';
                    row[i][num] = col[j][num] = box[boxIdx][num] = false;
                }
            }
            return false;
        }*/
       // ULTRA FAST SOLVED ALGORITHM FOR SUDOKU
         void solveSudoku(vector<vector<char>>& board) {
            solve(board);
        }
    private:
        bool isValid(vector<vector<char>>& board, int row, int col, char num) {
            for (int x = 0; x < 9; x++) {
                if (board[row][x] == num) return false; // check row
                if (board[x][col] == num) return false; // check column
                int boxRow = 3 * (row / 3) + x / 3;
                int boxCol = 3 * (col / 3) + x % 3;
                if (board[boxRow][boxCol] == num) return false; // check 3x3 box
            }
            return true;
        }

        bool solve(vector<vector<char>>& board) {
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    if (board[i][j] == '.') {
                        for (char num = '1'; num <= '9'; num++) {
                            if (isValid(board, i, j, num)) {
                                board[i][j] = num;
                                if (solve(board)) return true;
                                board[i][j] = '.';
                            }
                        }
                        return false;
                    }
                }
            }
            return true;
        }   
};
int main(){
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    Solution obj;
    obj.solveSudoku(board);
    for(auto i : board){
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}