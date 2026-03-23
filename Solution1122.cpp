#include "../leetcode.h"

// 1122. Relative Sort Array

class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        unordered_map<int, int> map;
        for (int i = 0; i < arr2.size();++i)
            map[arr2[i]] = i;
        sort(arr1.begin(), arr1.end(), [&](int n1, int n2)
             { 
            int k1 = map.contains(n1) ? map[n1] : n1 + arr2.size();
            int k2 = map.contains(n2) ? map[n2] : n2 + arr2.size();
            return k1<k2; });
        return arr1;
    }
};