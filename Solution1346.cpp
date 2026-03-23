#include "../leetcode.h"
#include <unordered_set>

class Solution {
public:
    bool checkIfExist(vector<int> &arr) { 
        unordered_set<int> hashtable;
        for (auto v : arr) {
            if (hashtable.contains(v * 2)) return true;
            if (v % 2 == 0 && hashtable.contains(v / 2)) return true;
            hashtable.insert(v);
        }
        return false;
    }
};