//Create Sorted Array through Instructions
#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    vector<int> bit;
    int n;
    Fenwick(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }
    void update(int idx, int val) {
        for (; idx <= n; idx += idx & -idx)
            bit[idx] += val;
    }
    int query(int idx) {
        int sum = 0;
        for (; idx > 0; idx -= idx & -idx)
            sum += bit[idx];
        return sum;
    }
};

class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        const int MOD = 1e9 + 7;
        int maxVal = *max_element(instructions.begin(), instructions.end());
        Fenwick fenw(maxVal);
        long long cost = 0;

        for (int i = 0; i < instructions.size(); i++) {
            int x = instructions[i];
            int smaller = fenw.query(x - 1);               
            int greater = i - fenw.query(x);                
            cost += min(smaller, greater);
            cost %= MOD;
            fenw.update(x, 1);
        }

        return (int)cost;
    }
};

int main() {
    Solution sol;
    vector<int> instructions1 = {1,5,6,2};
    cout << sol.createSortedArray(instructions1) << endl; 

    vector<int> instructions2 = {1,2,3,6,5,4};
    cout << sol.createSortedArray(instructions2) << endl;

    vector<int> instructions3 = {1,3,3,3,2,4,2,1,2};
    cout << sol.createSortedArray(instructions3) << endl; 
}
