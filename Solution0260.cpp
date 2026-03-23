// #include "../leetcode.h"

class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        unordered_map<int, int> map;

        // Counting occurrences of each number
        for(int num : nums){
            if(map.find(num) != map.end()){
                map[num]++;
            }else{
                map[num] = 1;
            }
        }

        // Finding single numbers
        vector<int> singleNumbers;
        for(const auto& item : map){
            if(item.second == 1) {
                singleNumbers.push_back(item.first);
            }
        }

        return singleNumbers;
    }
};
