/*
    Sep 05, 2026 18:50
    Runtime 3ms, beats 99.83%
    Memory 9.06MB, beats 86.28%
*/

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        if ( m > n) return 0;

        vector<unsigned long long> dp(m + 1, 0);
        dp[0] = 1; // the empty string is a subsequence of any string

        for (int i = 1; i <= n; ++i) {
            for (int j = m; j >= 1; --j) {
                if (s[i - 1] == t[j - 1]) {
                    dp[j] += dp[j - 1];
                }
            }
        }

        return dp[m];
    }
};
