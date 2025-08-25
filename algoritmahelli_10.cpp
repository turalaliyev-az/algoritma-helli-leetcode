//Wildacrd Matching Problem
//https://leetcode.com/problems/wildcard-matching/description/
//https://www.youtube.com/watch?v=3ZDZ-N0EPV0
//https://takeuforward.org/data-structure/wildcard-matching-dp-36/
//https://www.geeksforgeeks.org/wildcard-pattern-matching/
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
using namespace std;    
class Solution{
public:
bool isMatch(string s, string p) {
    /*
    int m = s.size(), n = p.size();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    dp[0][0] = true;
    for(int j = 1; j <= n; j++){
        if(p[j - 1] == '*'){
            dp[0][j] = dp[0][j - 1];
        }
    }
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(p[j - 1] == s[i - 1] || p[j - 1] == '?'){
                dp[i][j] = dp[i - 1][j - 1];
            }else if(p[j - 1] == '*'){
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            }else{
                dp[i][j] = false;
            }
        }
    }
    return dp[m][n];
    */
    //smart space optimization
    int m = s.size(), n = p.size();
    vector<bool> prev(n + 1, false), curr(n + 1, false);
    prev[0] = true;
    for(int j = 1; j <= n; j++){
        if(p[j - 1] == '*'){
            prev[j] = prev[j - 1];
        }
    }
    for(int i = 1; i <= m; i++){
        curr[0] = false;
        for(int j = 1; j <= n; j++){
            if(p[j - 1] == s[i - 1] || p[j - 1] == '?'){
                curr[j] = prev[j - 1];
            }else if(p[j - 1] == '*'){
                curr[j] = prev[j] || curr[j - 1];
            }else{
                curr[j] = false;
            }
        }
        prev = curr;
    }
       
    return prev[n];
}
};

int main(){
    Solution sol;
    string s = "aa", p = "a";
    cout << boolalpha << sol.isMatch(s, p) << endl; //true
    s = "aa", p = "*";
    cout << boolalpha << sol.isMatch(s, p) << endl; //true", p = "a*c?b";
    s = "cb", p = "?a";
    cout << boolalpha << sol.isMatch(s, p) << endl; //false

    return 0;
}