#include "../leetcode.h"

/*
Approach 2: priority queue (min-heap)
Dec 08, 2024 21:05
Runtime 63ms, Beats 71.62%
Memory 126.17MB, Beats 74.10%
*/

class Solution {
public:
    int maxTwoEvents(vector<vector<int>> &events) {
        // Create a min-heap to store the ending time with value.
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        sort(events.begin(), events.end());

        int maxVal = 0, maxSum = 0;

        for (auto &event : events) {
            // Pop all valid events from queue and take their maximum.
            while (pq.size() && pq.top().first < event[0]) {
                maxVal = max(maxVal, pq.top().second);
                pq.pop();
            }

            maxSum = max(maxSum, maxVal + event[2]);
            pq.push({event[1], event[2]});
        }

        return maxSum;
    }
};
