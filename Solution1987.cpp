/* 1987. Number of Unique Good Subsequences */
/* Runtime 3ms, Memory 15.00MB */

class Solution {
public:
    int numberOfUniqueGoodSubsequences(string binary) {
        const int MOD = 1e9 + 7;
        long long end0 = 0, end1 = 0; // distinct good subsequences ending with 0 and 1
        bool hasZero = false; 

        for (char c : binary) {
            if (c == '1') {
                // Extend every existing good subsequence with 1, plus the new subsequence 1 itself.
                // Overwrite (not add) to remove duplicates counted from earlier 1s.
                end1 = (end0 + end1 + 1) % MOD;
            } else {
                hasZero = true;
                // 0 can only extend existing an existing good subsequence; it cannot start one (leading zero).
                end0 = (end0 + end1) % MOD;
            }
        }

        long long result = (end0 + end1) % MOD;
        if (hasZero) result = (result + 1) % MOD; // account for the standalone 0
        return static_cast<int>(result);
    }
};
