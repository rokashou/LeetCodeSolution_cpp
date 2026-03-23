#include "../leetcode.h"

// 330. Patching array

/*
Given a sorted integer array nums and an integer n, add/patch elements to the array 
such that any number in the range [1, n] inclusive can be formed by the sum of some 
elements in the array.

Return the minimum number of patches required.
*/

class Solution
{
public:
    int minPatches(vector<int> &nums, int n)
    {
        long patches = 0, count = 1, i = 0, len = nums.size();
        while(count <= n){
            if(i<len && nums[i] <= count)
                count += nums[i++];
            else{
                count *= 2;
                patches++;
            }
        }
        return patches;
    }
};

