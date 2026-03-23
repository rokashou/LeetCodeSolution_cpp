#include "../leetcode.h"


// Official
class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        vector<vector<int>> dp(n, vector<int>(fuel + 1));
        for(int i = 0; i<=fuel; i++) {
            dp[finish][i] = 1;
        }

        int ans = 0;
        for (int j = 0; j <= fuel; j++) {
            for (int i = 0; i < n; i++) {
                for (int k = 0; k < n; k++) {
                    if (k == i) {
                        continue;
                    }
                    if (abs(locations[i] - locations[k]) <= j) {
                        dp[i][j] = (dp[i][j] + dp[k][j - abs(locations[i] - locations[k])]) %
                                   1000000007;
                    }
                }
            }
        }

        return dp[start][fuel];
    }
};



// Time: O(NlogN + NF)
// Space: O(NF)
class Solution {
public:
    int countRoutes(vector<int> &A, int start, int finish, int fuel) {
        int mod = 1e9 + 7, s = A[start], f = A[finish];
        sort(begin(A), end(A));
        start = lower_bound(begin(A), end(A), s) - begin(A);
        finish = lower_bound(begin(A), end(A), f) - begin(A);
        vector<vector<int>> left(A.size(), vector<int>(fuel + 1));
        vector<vector<int>> right(A.size(), vector<int>(fuel + 1));
        for (int f = 1; f <= fuel; ++f) {
            for (int j = 0; j < A.size() - 1; ++j) {
                int d = A[j + 1] - A[j];
                if (f > d)
                    left[j][f] = (right[j + 1][f - d] + 2 * left[j + 1][f - d] % mod) % mod;
                else if (f == d)
                    left[j][f] = j + 1 == start;
            }
            for (int j = 1; j < A.size(); ++j) {
                int d = A[j] - A[j - 1];
                if (f > d)
                    right[j][f] = (left[j - 1][f - d] + 2 * right[j - 1][f - d] % mod) % mod;
                else if (f == d)
                    right[j][f] = j - 1 == start;
            }
        }
        int ans = start == finish;
        for (int f = 1; f <= fuel; ++f)
            ans = ((ans + left[finish][f]) % mod + right[finish][f]) % mod;
        return ans;
    }
};