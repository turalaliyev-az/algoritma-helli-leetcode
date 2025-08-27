//valid number .cpp
#include <iostream>
#include <string>
#include <cctype>
using namespace std;    
class Solution {
public:
bool isNumber(string s){

    int n = s.size();
    int i = 0;
   
    while(i < n && isspace(s[i])) i++;
    if(i < n && (s[i] == '+' || s[i] == '-')) i++;
    bool isNumeric = false;
    while(i < n && isdigit(s[i])){
        i++;
        isNumeric = true;
    }
    if(i < n && s[i] == '.'){
        i++;
        while(i < n && isdigit(s[i])){
            i++;
            isNumeric = true;
        }
    }
    if(isNumeric && i < n && (s[i] == 'e' || s[i] == 'E')){
        i++;
        isNumeric = false;
        if(i < n && (s[i] == '+' || s[i] == '-')) i++;
        while(i < n && isdigit(s[i])){
            i++;
            isNumeric = true;
        }
    }
    while(i < n && isspace(s[i])) i++;
    return isNumeric && i == n;
}
};

int main(){
    Solution sol;   
    string s = "99e2.5";
    if(sol.isNumber(s)){
        cout << "true" << endl;
    }else{
        cout << "false" << endl;
    }
    return 0;
}