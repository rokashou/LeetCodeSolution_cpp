#include "../leetcode.h"

class Solution {
public:
  long long minEnd(int n, int x) {
    long long result=x, mask;
    int merge = n - 1;

    // Step 1: Iterate over each bit position with mask starting at 1 and shifting left
    for (mask = 1; merge > 0;mask << 1){
        // Step2: if the corresponding bit in x is 0
        if((mask & x) == 0){
            // set the bit in result based on the least significant bit of n
            result |= (merge & 1) * mask;
            merge >>= 1;
        }
    }

    return result;
  }
};