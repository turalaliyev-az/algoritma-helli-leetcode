// integer_to_roman.cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
private:
   inline string convertDigitFast(int digit, int pos, const vector<char>& sym) {
    if (digit == 0) return "";

    int i = pos * 2;
    char one = sym[i];
    char five = sym[i + 1];
    char ten = sym[i + 2];

    switch (digit) {
        case 1: return string(1, one);
        case 2: return string(2, one);
        case 3: return string(3, one);
        case 4: return string() + one + five;
        case 5: return string(1, five);
        case 6: return string() + five + one;
        case 7: return string() + five + one + one;
        case 8: return string() + five + one + one + one;
        case 9: return string() + one + ten;
        default: return "";
    }
}

public:
    string intToRoman(int num) {
        vector<char> sym = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        vector<int> digits;

        while (num > 0) {
            digits.push_back(num % 10);
            num /= 10;
        }

        reverse(digits.begin(), digits.end()); 
        string result = "";

        for (int i = 0; i < digits.size(); ++i) {
            int pos = digits.size() - 1 - i; 

            if (pos == 3) { 
                result.append(digits[i], 'M');
            } 
            else if (pos < 3) {  
                result += convertDigitFast(digits[i], pos, sym);
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    int num;
    cout << "Enter number (1 - 3999): ";
    cin >> num;

    if (num < 1 || num > 3999) {
        cout << " 1 and 3999." << endl;
        return 0;
    }

    string result = sol.intToRoman(num);
    cout << "Integer: " << num << " -> Roman Numeral: " << result << endl;

    return 0;
}
