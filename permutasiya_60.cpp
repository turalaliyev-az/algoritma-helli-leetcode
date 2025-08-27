//Permutation sequence
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string getPermutation(int n, int k) {
        //very high time complexity
        vector <int > v;
        for(int i =1; i<=n; i++){
            v.push_back(i);
        }
        int cnt = 0;
        vector <int > fact(n+1, 1);
        for(int i =1; i<=n; i++){
            fact[i] = i * fact[i-1];
        }
        k--;
        string ans = "";
        for(int i =1; i<=n; i++){
            int idx = k / fact[n-i];
            ans += to_string(v[idx]);
            v.erase(v.begin() + idx);
            k = k % fact[n-i];
        }
        return ans;
        /*
        do{
            cnt++;
            if(cnt == k){
                string ans = "";
                for(auto it : v){
                    ans += to_string(it);   
                }
                return ans;
            }
        }while(next_permutation(v.begin(), v.end()));*/
        return "";
    }
};  


int main() {
    Solution obj;
    int n = 9, k = 3;
    
    cout << obj.getPermutation(n, k) << endl;
    return 0;
}