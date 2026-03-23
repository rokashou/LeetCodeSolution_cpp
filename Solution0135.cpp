#include "../leetcode.h"

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int n = ratings.size();
        int count = n, i = 1;
        while(i<n){
            if(ratings[i] == ratings[i-1]){
                i++;
                continue;
            }

            // For increasing slope
            int peak = 0;
            while(ratings[i] > ratings[i-1]){
                peak++;
                count += peak;
                i++;
                if(i==n)
                    return count;
            }

            // For decreasing slope
            int valley = 0;
            while (i < n && ratings[i] < ratings[i-1]){
                valley++;
                count += valley;
                i++;
            }
            count -= min(peak, valley); // keep only the higher peak
        }
        return count;
    }
};