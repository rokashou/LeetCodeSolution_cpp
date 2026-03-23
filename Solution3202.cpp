#include "../leetcode.h"

class Solution {
public:
    int maximumLength(vector<int> &nums, int k) {
        vector<vector<int>> dp(k, vector<int>(k, 0));
        int ans = 0;

        for (int num : nums){
            int x = num % k;
            for (int i = 0; i < k;i++){
                dp[i][x] = dp[x][i] + 1;
                ans = max(ans, dp[i][x]);
            }
        }

        return ans;
    }
};