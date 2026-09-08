/* 126. Word Ladder II */
/* 7ms, 13.38MB */

#include "../leetcode.h"
#include <unordered_set>

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string> &wordList) {
        vector<vector<string>> result;
        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        // endWord must exist in the dictionary, otherwise no path is possible
        if (wordSet.find(endWord) == wordSet.end()) return result;

        // beginWord should not be reused as an intermediate word
        wordSet.erase(beginWord);

        // parents[word] = all predecessor words that can transform into "word"
        // on some shortest path
        unordered_map<string, vector<string>> parents;

        unordered_set<string> currentLevel{beginWord};
        bool found = false;

        while (!currentLevel.empty() && !found){
            // remove all words used in this level only after the level starts,
            // so words within the same level cannot reference each other
            for (const string& w : currentLevel) {
                wordSet.erase(w);
            }

            unordered_set<string> nextLevel;
            for (const string& word : currentLevel) {
                string candidate = word;
                for (int i = 0; i < (int)candidate.size(); ++i){
                    char original = candidate[i];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (c == original) continue;
                        candidate[i] = c;
                        if (wordSet.find(candidate) != wordSet.end()) {
                            parents[candidate].push_back(word);
                            nextLevel.insert(candidate);
                            if (candidate == endWord) found = true;
                        }
                    }
                    candidate[i] = original;  // restore before next position
                }
            }
            currentLevel = move(nextLevel);
        }

        if (!found) return result;

        // reconstruct all shortest paths by backtracking from endWord to beginWord
        vector<string> path{endWord};
        function<void(const string&)> backtrack = [&](const string& word) {
            if (word == beginWord) {
                vector<string> full(path.rbegin(), path.rend());
                result.push_back(full);
                return;
            }
            for (const string& p : parents[word]) {
                path.push_back(p);
                backtrack(p);
                path.pop_back();
            }
        };
        backtrack(endWord);
        
        return result;
    }
};
