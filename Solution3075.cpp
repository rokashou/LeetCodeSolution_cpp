#include "../leetcode.h"

class Solution
{
public:
    long long maximumHappinessSum(vector<int> &happiness, int k)
    {
        long long result = 0;
        sort(happiness.begin(), happiness.end(), greater<int>());

        for (int i = 0; i < k;++i){
            if(happiness[i]<i)
                continue;
            result += happiness[i] - i;
        }
        return result;
    }
};
