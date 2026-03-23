#include "../leetcode.h"

// 514. Freedom Trail

class Solution
{
public:
    vector<vector<int>> dp;
    int util(string &ring, string &key, int index_key, int index, vector<vector<int>> &ve)
    {
        if (index_key == key.size())
            return 0;
        if (dp[index][index_key] != -1)
            return dp[index][index_key];
        int ans = INT_MAX;
        int n = ring.size();
        for (int i : ve[key[index_key] - 'a'])
        {
            ans = min(ans, min((i - index + n) % n, (index - i + n) % n) + util(ring, key, index_key + 1, i, ve));
        }
        return dp[index][index_key] = ans;
    }
    int findRotateSteps(string ring, string key)
    {
        dp.resize(ring.size() + 1, vector<int>(key.size() + 1, -1));
        vector<vector<int>> ve(26);
        for (int i = 0; i < ring.size(); i++)
        {
            ve[ring[i] - 'a'].push_back(i);
        }
        return util(ring, key, 0, 0, ve) + key.size();
    }
};
