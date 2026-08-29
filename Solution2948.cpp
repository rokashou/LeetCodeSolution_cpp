/*
    2026/08/29
    Runtime 155ms, Beats 83.10%
    Memory 131.24MB, Beats 92.68%
*/

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        
        // 依「值」排序的索引陣列
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return nums[a] < nums[b];
        });
        
        vector<int> result(n);
        
        int i = 0;
        while (i < n) {
            int j = i;
            // 只要相鄰(排序後)差值 <= limit，就屬於同一連通群組
            while (j + 1 < n && nums[idx[j + 1]] - nums[idx[j]] <= limit) {
                j++;
            }
            
            // 收集此群組原本的下標，排序後由小到大放入(已排序的)值
            vector<int> groupIndices(idx.begin() + i, idx.begin() + j + 1);
            sort(groupIndices.begin(), groupIndices.end());
            
            for (int k = 0; k < (int)groupIndices.size(); k++) {
                result[groupIndices[k]] = nums[idx[i + k]];
            }
            
            i = j + 1;
        }
        
        return result;
    }
};
