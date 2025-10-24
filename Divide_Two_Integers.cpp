//29 Divide Two Integers
#include <iostream>
#include <climits>
using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        
        long long a = labs(dividend);
        long long b = labs(divisor);
        long long result = 0;
        
        while (a >= b) {
            long long temp = b, multiple = 1;
            while (a >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            a -= temp;
            result += multiple;
        }
        
        return (dividend > 0) == (divisor > 0) ? result : -result;
    }
};
int main() {
    Solution sol;
    int dividend = 10;
    int divisor = 3;
    int result = sol.divide(dividend, divisor);
    cout << "Quotient: " << result << endl;
    return 0;
}