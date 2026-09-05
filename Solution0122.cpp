
/* 122. Best Time to Buy and Sell Stock II */
/* Runtime: 0ms, Memory: 20.08MB */

class Solution {
public:
    int maxProfit(vector<int> &prices) { 
        int profit = 0; 
        // Accumulate profit for every consecutive price increase
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1]) {
                profit += prices[i] - prices[i - 1];
            }
        }
        return profit;
    }
};
