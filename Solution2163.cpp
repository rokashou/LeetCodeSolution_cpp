#include "../leetcode.h"

class Solution {
public:
    long long minimumDifference(vector<int> &nums) { 
        int n3 = nums.size();
        int n = n3 / 3;
        long long ans = LLONG_MAX;

        vector<long long> left_min(n3);
        priority_queue<long long> max_heap;
        long long left_sum = 0;

        for (int i = 0; i < 2 * n;++i){
            left_sum += nums[i];
            max_heap.push(nums[i]);
            if(max_heap.size() > n){
                left_sum -= max_heap.top();
                max_heap.pop();
            }
            if(max_heap.size() == n){
                left_min[i] = left_sum;
            }
        }

        priority_queue<long long, vector<long long>, greater<long long>>
            min_heap;
        long long right_sum = 0;

        for (int i = n3 - 1; i >= n;--i){
            right_sum += nums[i];
            min_heap.push(nums[i]);
            if(min_heap.size() > n){
                right_sum -= min_heap.top();
                min_heap.pop();
            }
            if(min_heap.size() == n){
                ans = min(ans, left_min[i - 1] - right_sum);
            }
        }

        return ans;
    }
};