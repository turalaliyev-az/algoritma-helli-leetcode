//Maximum Area of Longest Diagonal Rectangle in a 2D Matrix
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
class Solution {
public:
int areaofMaxDiagonal (vector<vector<int>>& dimensions) {
/*1 <= dimensions.length <= 100
dimensions[i].length == 2
1 <= dimensions[i][0], dimensions[i][1] <= 100*/
 double maxDiagonal = 0;
    int maxArea = 0;

    for(auto& rect : dimensions) {
        int length = rect[0];
        int width = rect[1];
        double diag = sqrt(length*length + width*width);
        int area = length * width;

        if(diag > maxDiagonal) {
            maxDiagonal = diag;
            maxArea = area;
        } else if(diag == maxDiagonal) {
            if(area > maxArea)
                maxArea = area;
        }
    }

    return maxArea;
}
};

int main(){
    Solution sol;
    vector<vector<int>> dimensions = {{4,10},{4,9},{9,13},{10,8}};
    cout << sol.areaofMaxDiagonal(dimensions) << endl; // 80
    return 0;
}
