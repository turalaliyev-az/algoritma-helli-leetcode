//sliding window + hash map

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector <int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;

        int wordLength = words[0].size();
        int totalWords = words.size();
        int totalLength = wordLength * totalWords;
        unordered_map<string, int> wordCount;

        for (const string& word : words) {
            wordCount[word]++;
        }

for (int offset = 0; offset < wordLength; offset++) {
    int left = offset; // pencerenin solu
    int count = 0;
    unordered_map<string, int> seenWords;

    for (int right = offset; right + wordLength <= s.size(); right += wordLength) {
        string word = s.substr(right, wordLength);

        if (wordCount.count(word)) {
            seenWords[word]++;
            count++;

            while (seenWords[word] > wordCount[word]) {
                string leftWord = s.substr(left, wordLength);
                seenWords[leftWord]--;
                left += wordLength;
                count--;
            }

            if (count == totalWords) {
                result.push_back(left);
            }
        } else {
            seenWords.clear();
            count = 0;
            left = right + wordLength;
        }
    }
}


        return result;
    }       
};
int main() {   
    Solution solution;
    string s = "barfoothefoobarman";
    vector<string> words = {"foo", "bar"};
    vector<int> indices = solution.findSubstring(s, words);
    cout << "Starting indices of substring: ";
    for (int index : indices) {
        cout << index << " ";
    }
    cout << endl;

    return 0; // This is a placeholder to complete the code structure.
}