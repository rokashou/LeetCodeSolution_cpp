/* 3904. Smallest Stable Index II */
/* Runtime: 12ms, Beats 51.64% */
/* Memory: 202.62MB, Beats 76.32% */

class Solution {
public:
    int firstStableIndex(vector<int> &nums, int k) {
        int n = nums.size();

        // Step 1: Precompute suffix minimum: suffixMin[i] = min(nums[i..n-1])
        vector<int> suffixMin(n);
        suffixMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suffixMin[i] = min(nums[i], suffixMin[i + 1]);
        }

        // Step 2: Single left-to-right pass maintaining prefix maximum
        int prefixMax = nums[0];
        for (int i = 0; i < n; ++i) {
            prefixMax = max(prefixMax, nums[i]); // running max(nums[0..i])
            long long instability = (long long)prefixMax - (long long)suffixMin[i]; 
            if (instability <= k) {
                return i; // Found the first stable index
            }
        }

        return -1; // No stable index found
    }
};
