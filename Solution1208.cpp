#include "../leetcode.h"

// 1208. Get Equal Substrings Within Budget

/* 
The cost for change s[i] to t[i] is Abs(s[i]-t[i]) .
*/



class Solution // Sliding Window as Official Solution
{
public:
    int equalSubstring(string s, string t, int maxCost)
    {
        int N = s.size();

        int maxLen = 0;
        // Start index of the current substring
        int start = 0;
        // Cost of converting the current substring in s to t
        int currCost = 0;

        for (int i = 0; i < N;++i){
            // Add the current index to the substring
            currCost += abs(s[i] - t[i]);

            // Remove the indices from the left end till the cost becomes less than allowed
            while(currCost > maxCost){
                currCost -= abs(s[start] - t[start]);
                start++;
            }

            maxLen = max(maxLen, i - start + 1);
        }

        return maxLen;
    }
};