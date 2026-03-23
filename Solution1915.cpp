#include "../leetcode.h"
class Solution
{
public:
    long long wonderfulSubstrings(string word)
    {
        long long n = word.size(), mask = 0, result = 0;
        ;
        vector<long long> count(1024);
        count[0] = 1;
        for (char c : word)
        {
            mask ^= 1 << (c - 'a');
            result += count[mask]++;
            for (long long i = 0; i < 10; ++i)
                result += count[mask ^ (1 << i)];
        }
        return result;
    }
};