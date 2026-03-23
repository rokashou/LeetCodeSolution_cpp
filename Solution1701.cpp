#include "../leetcode.h"

class Solution
{
public:
    double averageWaitingTime(vector<vector<int>> &customers)
    {
        int curTime = 0;
        double totalTime = 0;

        for (auto cus : customers)
        {
            curTime = max(curTime, cus[0]) + cus[1];
            totalTime += curTime - cus[0];
        }

        return totalTime / customers.size();
    }
};