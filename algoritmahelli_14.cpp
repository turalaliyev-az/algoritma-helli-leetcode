//N-queens problem using backtracking
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
using namespace std;    
//ilk çözüm
/*
class Solution{
public:
   vector<vector<string>> solveNQueens(int n) {
        // Initialize the board with '.'
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        backtrack(result, board, 0, n);
        return result;  
        
    }

private:
    bool isValid(const vector<string>& board, int row, int col, int n) {
        // Check column
        for (int i = 0; i < row; ++i)
            if (board[i][col] == 'Q') return false;
        // Check diagonal 
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
            if (board[i][j] == 'Q') return false;
        // Check diagonal 
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
            if (board[i][j] == 'Q') return false;
        return true;
    }

    void backtrack(vector<vector<string>>& result, vector<string>& board, int row, int n) {
        if (row == n) {
            result.push_back(board);
            return;
        }
        for (int col = 0; col < n; ++col) {
            if (isValid(board, row, col, n)) {
                board[row][col] = 'Q';
                backtrack(result, board, row + 1, n);
                board[row][col] = '.';
            }
        }
    }
};
int main(){
    Solution sol;
    int n = 4;
    vector<vector<string>> result = sol.solveNQueens(n);
    for(auto& board : result){
        for(auto& row : board){
            cout << row << endl;
        }
        cout << endl;
    }
    return 0;
} 
    */

// Daha optimize edilmiş çözüm
using namespace std;

// Backtracking fonksiyonu
void solveNQueens(int row, int n, vector<string> &board,
                  vector<bool> &cols, vector<bool> &diag1, vector<bool> &diag2,
                  vector<vector<string>> &solutions) {

    if (row == n) {  // Tüm satırlar yerleşti → çözümü kaydet
        solutions.push_back(board);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (!cols[col] && !diag1[row + col] && !diag2[row - col + n - 1]) {
            // Bu konum güvenli → vezir yerleştir
            board[row][col] = 'Q';
            cols[col] = diag1[row + col] = diag2[row - col + n - 1] = true;

            solveNQueens(row + 1, n, board, cols, diag1, diag2, solutions);

            // Backtrack → veziri kaldır
            board[row][col] = '.';
            cols[col] = diag1[row + col] = diag2[row - col + n - 1] = false;
        }
    }
}

// Ana fonksiyon
vector<vector<string>> nQueens(int n) {
    vector<vector<string>> solutions;
    vector<string> board(n, string(n, '.'));
    
    // Hızlı kontrol için boolean dizileri
    vector<bool> cols(n, false);       // Sütunlar
    vector<bool> diag1(2*n - 1, false); // Sol üst -> sağ alt çapraz
    vector<bool> diag2(2*n - 1, false); // Sağ üst -> sol alt çapraz

    solveNQueens(0, n, board, cols, diag1, diag2, solutions);

    return solutions;
}

// Örnek kullanım
int main() {
    int n = 4;
    vector<vector<string>> result = nQueens(n);

    for (auto &sol : result) {
        for (auto &row : sol) {
            cout << row << endl;
        }
        cout << "------" << endl;
    }

    return 0;
}