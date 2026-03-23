#include "../leetcode.h"

// 633. Sum of Square Numbers

class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        long l = 0, r = sqrt(c);
        while(l<=r){
            long sum = l * l + r * r;
            if(sum == c){
                return true;
            }
            if(sum < c){
                l++;
            }else{
                r--;
            }
        }
        return false;
    }
};