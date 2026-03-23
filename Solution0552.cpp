#include "../leetcode.h"

// 552. Student Attendance Record II


class Solution1 // Top-Down DP with Memoization
{
    const int MOD = 1000000007;
    // Cache to store sub-problem results.
    vector<vector<vector<int>>> memo;

public:
    // Recursive function to return the count of combinations of length 'n' eligible for the award.
    int eligibleCombinations(int n, int totalAbsences, int consecutiveLates){
        // if the combination has become not eligible for the award,
        // then we will not count any combintions that cn be made using it.
        if(totalAbsences >= 2 or consecutiveLates >= 3)
            return 0;

        // if we have generated a combination of length 'n' we will count it.
        if(n==0)
            return 1;

        // if we have already seen this sub-problem earlier, we return the stored result.
        if(memo[n][totalAbsences][consecutiveLates] != -1){
            return memo[n][totalAbsences][consecutiveLates];
        }

        int count = 0;
        // we choose 'P' for the current position.
        count = eligibleCombinations(n - 1, totalAbsences, 0);
        // we choose 'A' for the current position.
        count = (count + eligibleCombinations(n - 1, totalAbsences + 1, 0)) % MOD;
        // we choose 'L' for the current position.
        count = (count + eligibleCombinations(n - 1, totalAbsences, consecutiveLates + 1)) % MOD;

        // return and store the current sub-problem result in the cache
        return memo[n][totalAbsences][consecutiveLates] = count;
    }

    int checkRecord(int n)
    {
        // Initialize the cache
        memo = vector<vector<vector<int>>>(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        // Return count of combinations of length 'n' eligible for the award.
        return eligibleCombinations(n, 0, 0);
    }
};


class Solution2 // Bottom-UP DP
{


public:
    int checkRecord(int n)
    {
        const int MOD = 1000000007;
        // Cache to store sub-problem results.
        vector<vector<vector<int>>> dp = vector<vector<vector<int>>>(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        // Base case: there is 1 string of length 0 with zero 'A' and zero 'L'.
        dp[0][0][0] = 1;

        // Iterate on smaller sub-problems and use the current smaller sub-problem 
        // to generate results ofr bigger sub-problems.
        for (int len = 0; len < n;++len){
            for (int totalAbsences = 0; totalAbsences <= 1;++totalAbsences){
                for (int consecutiveLates = 0 consecutiveLates <= 2;++consecutiveLates){
                    // Store the count when 'P' is chosen.
                    dp[len + 1][totalAbsences][0] = (
                        dp[len + 1][totalAbsences][0] +
                        dp[len][totalAbsences][consecutiveLates]
                        ) % MOD;
                    // store the count when 'A' is chosen.
                    if(totalAbsences < 1){
                        dp[len + 1][totalAbsences + 1][0] = (
                            dp[len + 1][totalAbsences + 1][0] +
                            dp[len][totalAbsences][consecutiveLates]
                            ) % MOD;

                    }

                    // store the count when 'L' is chosen.
                    if(consecutiveLates < 2){
                        dp[len + 1][totalAbsences][consecutiveLates + 1] = (
                            dp[len + 1][totalAbsences][consecutiveLates + 1] + 
                            dp[len][totalAbsences][consecutiveLates]
                            ) % MOD;
                    }
                }
            }
        }

        // sum up the counts for all combinations of length 'n' with different absent and late counts.
        int count = 0;
        for (int totalAbsences = 0; totalAbsences <= 1;++totalAbsences){
            for (int consecutiveLates = 0; consecutiveLates <= 2;++consecutiveLates){
                count = (count + dp[n][totalAbsences][consecutiveLates]) % MOD;
            }
        }
        return count;
    }
};

class Solution3 // Bottom-up DP, Space Optimized
{
public:
    int checkRecord(int n)
    {

    }
}