#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
    // Store all words in unordered set for O(1) lookup
    unordered_set<string> st(wordList.begin(), wordList.end());
    
    // Queue to store paths (each path is a vector of strings)
    queue<vector<string>> q;
    q.push({beginWord});
    
    // Track words used at current level for deferred deletion
    vector<string> usedOnLevel;
    usedOnLevel.push_back(beginWord);
    
    int level = 0;
    vector<vector<string>> ans;
    
    while (!q.empty()) {
        vector<string> vec = q.front();
        q.pop();
        
        // Level change detected: remove words from previous level
        if (vec.size() > level) {
            level++;
            for (auto it : usedOnLevel) {
                st.erase(it);
            }
            usedOnLevel.clear();
        }
        
        string word = vec.back();
        
        // If we reached the end word, add the path to answer
        if (word == endWord) {
            if (ans.size() == 0) {
                ans.push_back(vec);
            }
            else if (ans[0].size() == vec.size()) {
                ans.push_back(vec);
            }
        }
        
        // Try changing each character of the word
        for (int i = 0; i < word.size(); i++) {
            char original = word[i];
            for (char c = 'a'; c <= 'z'; c++) {
                word[i] = c;
                if (st.count(word) > 0) {
                    vec.push_back(word);
                    q.push(vec);
                    usedOnLevel.push_back(word);
                    vec.pop_back();
                }
            }
            word[i] = original;  // Restore original character
        }
    }
    return ans;
}

int main() {
    // Test Case 1
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    
    vector<vector<string>> result = findSequences(beginWord, endWord, wordList);
    
    cout << "Test Case 1 Results:" << endl;
    if (result.empty()) {
        cout << "-1 (No sequence found)" << endl;
    } else {
        for (const auto& path : result) {
            for (const auto& word : path) {
                cout << word << " ";
            }
            cout << endl;
        }
    }
    
    cout << "\n-------------------\n" << endl;
    
    // Test Case 2: No sequence exists
    beginWord = "hit";
    endWord = "cog";
    wordList = {"hot", "dot", "dog", "lot", "log"};
    
    result = findSequences(beginWord, endWord, wordList);
    
    cout << "Test Case 2 Results:" << endl;
    if (result.empty()) {
        cout << "-1 (No sequence found)" << endl;
    } else {
        for (const auto& path : result) {
            for (const auto& word : path) {
                cout << word << " ";
            }
            cout << endl;
        }
    }
    
    cout << "\n-------------------\n" << endl;
    
    // Test Case 3: Multiple shortest paths
    beginWord = "red";
    endWord = "tax";
    wordList = {"ted", "tex", "red", "tax", "tad", "den", "rex", "pee"};
    
    result = findSequences(beginWord, endWord, wordList);
    
    cout << "Test Case 3 Results:" << endl;
    if (result.empty()) {
        cout << "-1 (No sequence found)" << endl;
    } else {
        for (const auto& path : result) {
            for (const auto& word : path) {
                cout << word << " ";
            }
            cout << endl;
        }
    }
    
    return 0;
}