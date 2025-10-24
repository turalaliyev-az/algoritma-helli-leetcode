// reverse integer
#include <iostream>
#include <climits>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        long long reversed = 0;
        while (x != 0) {
            int digit = x % 10;
            reversed = reversed * 10 + digit;
            x /= 10;
        }
        if (reversed < INT_MIN || reversed > INT_MAX) {
            return 0;
        }
        return static_cast<int>(reversed);
    }
};
int main() {
    Solution sol;
    int x = -12345;
    int result = sol.reverse(x);
    cout << "Reversed integer: " << result << endl;
    return 0;
}