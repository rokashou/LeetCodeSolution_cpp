#include "../leetcode.h"

class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &score)
    {
        int N = score.size();
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < N;i++){
            pq.push({score[i], i});
        }
        vector<string> rank(N);
        int place = 1;
        while(!pq.empty()){
            int originalIndex = pq.top().second;
            pq.pop();
            switch(place){
            case 1:
                rank[originalIndex] = "Gold Medal";
                break;
            case 2:
                rank[originalIndex] = "Silver Medal";
                break;
            case 3:
                rank[originalIndex] = "Bronze Medal";
                break;
            default:
                rank[originalIndex] = to_string(place);
            }
            place++;
        }
        return rank;
    }
};