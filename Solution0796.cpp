#include "../leetcode.h"

class Solution {
public:
  bool rotateString(string s, string goal) {
    if(s.length() != goal.length())
      return false;

    int slen = s.length();
    std::size_t startIdx = goal.find(s[0]);
    int idx1 = 0, idx2 = startIdx;
    int count = 0;
    if(startIdx == string::npos)
      return false;
    while (count < slen) {
      if (s[idx1] != goal[idx2]) {
        startIdx = goal.find(s[0], startIdx + 1);
        if (startIdx != string::npos) {
          idx1 = 0;
          idx2 = startIdx;
          count = 0;
          continue;
        } else
          return false;
      }
      idx1 = (idx1 + 1) % slen;
      idx2 = (idx2 + 1) % slen;
      count++;
    }
    return true;
  }


};