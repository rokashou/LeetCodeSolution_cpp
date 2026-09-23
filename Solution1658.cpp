/* 1658. Minimum Operations to Reduce X to Zero */
/* 2026-09-24 00:07: 6ms, 102.40MB */


class Solution {
public:
    int minOperations(vector<int> &nums, int x) { 
        int n = nums.size();
        long long total = 0;
        for (int v : nums)
            total += v;

        long long target = total - x;
        // All elements are positive, so any subarray sum is non-negative.
        if (target < 0) return -1;
        if (target == 0) return n; // remove everything

        int maxLen = -1;
        long long windowSum = 0;
        int left = 0;

        for (int right = 0; right < n; ++right){
            windowSum += nums[right];
            // Shrink from the left while the window sum exceeds target
            while(windowSum > target && left <= right){
                windowSum -= nums[left];
                ++left;
            }
            if(windowSum == target) {
                maxLen = max(maxLen, right - left + 1);
            }
        }

        return maxLen == -1 ? -1 : n - maxLen;
    }
};

