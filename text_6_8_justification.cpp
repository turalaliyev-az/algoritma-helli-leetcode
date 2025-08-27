// Text Justification
#include <bits/stdc++.h>
using namespace std;    
class Solution {
public:
 vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int currLen = 0;
        int start = 0;
        vector<string> result;
        for(int i =0 ; i < words.size(); i++){
          if(currLen + words[i].size() + (i - start) > maxWidth){
            string line;
            int spaceCount = maxWidth - currLen;
            int wordCount = i - start;
            if(wordCount == 1){
              line += words[start];
              line.append(spaceCount, ' ');
            }else{
              int spaceBetweenWords = spaceCount / (wordCount - 1);
              int extraSpaces = spaceCount % (wordCount - 1);
              for(int j = start; j < i; j++){
                line += words[j];
                if(j < i - 1){
                  line.append(spaceBetweenWords + (extraSpaces > 0 ? 1 : 0), ' ');
                  if(extraSpaces > 0) extraSpaces--;
                }
              }
            }
            result.push_back(line);
            currLen = 0;
            start = i;
          }
          currLen += words[i].size();
        }
        
        string lastLine;
        for(int i = start; i < words.size(); i++){
          lastLine += words[i];
          if(i < words.size() - 1) lastLine += ' ';
        }
        lastLine.append(maxWidth - lastLine.size(), ' ');
        result.push_back(lastLine);
        return result;
    }
};
int main(){
    Solution sol;   
    vector<string> words = {"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"};
    int maxWidth = 20;
    vector<string> result = sol.fullJustify(words, maxWidth);
    for(const string& line : result){
        cout << "\"" << line << "\"" << endl;
    }
    return 0;
}