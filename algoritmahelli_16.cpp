//Spiral matrix
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
  vector<int> result;
    int m = matrix.size();
    if (m == 0) return result;
    int n = matrix[0].size();
    
    int layers = (min(m, n) + 1) / 2; // katman sayısı

    for (int layer = 0; layer < layers; layer++) {
        // Üst satır: soldan sağa
        for (int j = layer; j < n - layer; j++)
            result.push_back(matrix[layer][j]);

        // Sağ sütun: yukarıdan aşağıya
        for (int i = layer + 1; i < m - layer; i++)
            result.push_back(matrix[i][n - layer - 1]);

        // Alt satır: sağdan sola
        if (m - layer - 1 > layer) {
            for (int j = n - layer - 2; j >= layer; j--)
                result.push_back(matrix[m - layer - 1][j]);
        }

        // Sol sütun: aşağıdan yukarıya
        if (n - layer - 1 > layer) {
            for (int i = m - layer - 2; i > layer; i--)
                result.push_back(matrix[i][layer]);
        }
    }
    
    return result;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    vector<int> result = sol.spiralOrder(matrix);
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}