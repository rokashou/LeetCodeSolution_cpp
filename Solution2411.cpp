#include "../leetcode.h"

class Solution {
public:
    vector<int> smallestSubarrays(vector<int> &nums) {
        int n = nums.size();
        vector<int> res(n);
        vector<int> lastPos(32, -1); // 每個 bit 最後一次出現的位置

        for (int i = n - 1; i >= 0; --i) {
            // 更新當前數字中的每個 bit 的最後出現位置
            for (int b = 0; b < 32; ++b) {
                if (nums[i] & (1 << b)) {
                    lastPos[b] = i;
                }
            }

            // 找出從 i 開始能覆蓋 OR 所需 bit 的最遠位置
            int maxLast = i;
            for (int b = 0; b < 32; ++b) {
                if (lastPos[b] != -1) {
                    maxLast = max(maxLast, lastPos[b]);
                }
            }

            res[i] = maxLast - i + 1;
        }

        return res;
    }
};

