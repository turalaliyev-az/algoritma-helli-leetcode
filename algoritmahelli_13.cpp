//partition labels
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
vector<int> partitionLabels(string s) {
    int n = s.size();
    vector<int> lastIndex(26, -1);
    for(int i = 0; i < n; i++){
        lastIndex[s[i] - 'a'] = i;
    }
    vector<int> result;
    int start = 0, end = 0;     
    for(int i = 0; i < n; i++){
        end = max(end, lastIndex[s[i] - 'a']);
        if(i == end){
            result.push_back(end - start + 1);
            start = i + 1;
        }
    }
    return result;
}
};
int main(){
    Solution sol;
    string s = "eccbbbbdec";
    vector<int> result = sol.partitionLabels(s);
    for(int len : result){
        cout << len << " ";
    }
    cout << endl; // 9 7 8
    return 0;
}