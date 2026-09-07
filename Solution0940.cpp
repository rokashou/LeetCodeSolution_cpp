/* 940. Distinct Subsequences II */
/* Runtime: 1ms, Memory: 8.85MB */

class Solution {
public:
    int distinctSubseqII(string s) { 
        const int MOD = 1e9 + 7;

        // total: number of distinct subsequences so far, including the empty one
        long long total = 1;

        // last[c]: value of 'total' right before character c was last appended
        vector<long long> last(26, 0);

        for (char c : s) {
            int idx = c - 'a';
            long long newTotal = (total * 2 - last[idx] % MOD + MOD) % MOD; 
            last[idx] = total; // record total BEFORE this occurrence is counted
            total = newTotal; 
        }
        
        // subtract 1 to remove the empty subsequence, adjust for possible negative mod
        return (int)((total - 1 + MOD) % MOD);
    }
};
