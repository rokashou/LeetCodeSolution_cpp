#include "../leetcode.h"

class Solution
{
public:
  int shortestSubarray(vector<int> &nums, int k)
  {
    int n = nums.size();

    // Size is n+1 to handle subarrays starting from index 0
    vector<long long> prefixSums(n + 1, 0);

    // Calculate prefix sums
    for (int i = 1; i <= n;i++){
      prefixSums[i] = prefixSums[i - 1] + nums[i - 1];
    }

    deque<int> condidateIndices;

    int shortestSubarrayLength = INT_MAX;

    for (int i = 0; i <= n;i++){
      // Remove condidates from front of deque where subarray sum meets target
      while(!condidateIndices.empty() &&
        prefixSums[i] - prefixSums[condidateIndices.front()] >= k){
          // Update shortest subarray length
          shortestSubarrayLength = min(shortestSubarrayLength, i - condidateIndices.front());
          condidateIndices.pop_front();
      }

      // Maintain monotonicity by removing indices with larger prefix sums
      while(!condidateIndices.empty() && 
        prefixSums[i] <= prefixSums[condidateIndices.back()]) {
        condidateIndices.pop_back();
      }

      // Add current index to condidates
      condidateIndices.push_back(i);
    }

    // Return -1 if no valid subarray found
    return shortestSubarrayLength == INT_MAX ? -1 : shortestSubarrayLength;
  }
};