#include "../leetcode.h"

class Solution {
public:
    int maximumLength(vector<int> &nums) { 
        int dp[2][2] = {{0, 0}, {0, 0}};
        int ans = 0;
        for (int x : nums) {
            x %= 2;
            for (int j = 0; j < 2;++j){
                dp[x][j] = dp[j][x] + 1;
                ans = max(ans, dp[x][j]);
            }
        }
        return ans;
    }
};