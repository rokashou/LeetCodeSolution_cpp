#include "../leetcode.h"

// 1296. Divide Array in Sets of K Consecutive Numbers

int ed[100001];

class Solution
{
public:
    bool isPossibleDivide(vector<int> &nums, int k)
    {
        sort(begin(nums), end(nums));
        int N = size(nums), cnt = 0, nx, base;

        for (int i = 0; i < N;)
        {
            int n = nums[i], s = i;
            if (!cnt)
                ++i, base = n + k;
            else if ((i += cnt) > N || nums[i - 1] != nx)
                return false;
            while (i < N && nums[i] == n)
                ++i;
            s = i - s;

            ed[n + k - base] = s - cnt;
            nx = ++n;
            cnt = s;
            if ((n -= base) >= 0)
                cnt -= ed[n], ed[n] = 0;
        }
        return !cnt;
    }
};
