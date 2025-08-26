//Diagonal Traverse
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    vector<int> result;
    for(int d = 0; d < m + n - 1; d++){
        if(d % 2 == 0){
            int r = min(d, m - 1);
            int c = d - r;
            while(r >= 0 && c < n){
                result.push_back(mat[r][c]);
                r--;
                c++;
            }
        }else{
            int c = min(d, n - 1);      
            int r = d - c;
            while(c >= 0 && r < m){
                result.push_back(mat[r][c]);
                r++;
                c--;
            }
        }
    }
    return result;
}
};
int main(){
    Solution sol;
    vector<vector<int>> mat = {{1,2,3},
                               {4,5,6},
                               {7,8,9}};
    vector<int> result = sol.findDiagonalOrder(mat);
    for(int num : result){
        cout << num << " "; 
    }
    cout << endl;
    return 0;
}