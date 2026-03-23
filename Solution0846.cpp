#include "../leetcode.h"

// 846. Hand of Straights

int ed[100001];

class Solution
{    

public:
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        sort(begin(hand), end(hand));
        int N = size(hand), cnt = 0, nx, base;

        for (int i = 0; i < N;)
        {
            int n = hand[i], s = i;
            if (!cnt)
                ++i, base = n + groupSize;
            else if ((i += cnt) > N || hand[i - 1] != nx)
                return false;
            while (i < N && hand[i] == n)
                ++i;
            s = i - s;

            ed[n + groupSize - base] = s - cnt;
            nx = ++n;
            cnt = s;
            if ((n -= base) >= 0)
                cnt -= ed[n], ed[n] = 0;
        }
        return !cnt;
    }
};