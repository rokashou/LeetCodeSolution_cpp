#include "../leetcode.h"


#include <ranges>
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        auto sens = splitByWhitespace(sentence);
        for (int index = 0; index < sens.size();index++){
            if(sens[index].substr(0,searchWord.length())==searchWord)
                return index + 1;
        }
        return -1;
    }

private:
    vector<string> splitByWhitespace(const string &str) {
        vector<string> tokens;
        for (auto word : std::views::split(str, ' ')) {
            tokens.emplace_back(word.begin(), word.end());
        }
        return tokens;
    }
};