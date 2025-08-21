#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isMatch(const string& s, const string& p) {
    int m = s.size(), n = p.size();
    //fast exit for empty pattern
    if (n == 0) return m == 0;  

    vector<vector<char>> dp(m+1, vector<char>(n+1, 0));
    //vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));

    dp[0][0] = true;

    // Boş s ile p'nin eşleşmesi (a*, a*b*, ... gibi)
    for (int j = 2; j <= n; ++j)
        if (p[j-1] == '*') dp[0][j] = dp[0][j-2];

    auto matches = [&](int i, int j) {
        // p[j-1] ile s[i-1] eşleşir mi?
        return i > 0 && (p[j-1] == '.' || p[j-1] == s[i-1]);
    };

    for (int i = 0; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (p[j-1] == '*') {
                // '*' sıfır kez kullan
                dp[i][j] = dp[i][j-2];
                // '*' en az bir kez kullan
                if (matches(i, j-1)) {
                    dp[i][j] = dp[i][j] || dp[i-1][j];
                }
            } else {
                if (matches(i, j)) dp[i][j] = dp[i-1][j-1];
            }
        }
    }
    return dp[m][n];
}

int main() {
    cout << boolalpha;
    cout << isMatch("aa", "a")   << " (false)\n";
    cout << isMatch("aa", "a*")  << " (true)\n";
    cout << isMatch("ab", ".*")  << " (true)\n";
    cout << isMatch("aab", "c*a*b") << " (true)\n";
    cout << isMatch("mississippi", "mis*is*p*.") << " (false)\n";
    return 0;
}
