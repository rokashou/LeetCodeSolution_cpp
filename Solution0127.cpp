#include "../leetcode.h"
#include <unordered_set>

/* 127. Word Ladder */
/* 19ms, 19.26MB */

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return 0;
        dict.erase(beginWord);

        unordered_set<string> beginSet{beginWord};
        unordered_set<string> endSet{endWord};
        int level = 1;

        while(!beginSet.empty() && !endSet.empty()) {
            // Always expand the smaller frontier to minimize branching
            if(beginSet.size() > endSet.size()) {
                swap(beginSet, endSet);
            }

            unordered_set<string> nextSet;
            for (const string& word : beginSet) {
                string current = word;
                for(int i = 0; i<(int)current.size(); ++i) {
                    char original = current[i];

                    for (char c = 'a'; c <= 'z';++c){
                        if (c == original) continue;
                        current[i] = c;
                        // Meeting the other frontier means a path is found
                        if(endSet.count(current)) {
                            return level + 1;
                        }
                        if(dict.count(current)) {
                            dict.erase(current); // mark visited by removing from dict
                            nextSet.insert(current);
                        }
                    }
                    current[i] = original; // restore before trying next position
                }
            }
            beginSet = move(nextSet);
            level++;
        }
        return 0;
    }
};

