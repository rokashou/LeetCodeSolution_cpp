#include "../leetcode.h"

class Solution0965 {
public:
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        int sum = 0;
        
        for (size_t i = 0; i < n; i++)
        {
            sum += rods[i];
        }

        int dp[2 * sum + 1];
        
    }
};