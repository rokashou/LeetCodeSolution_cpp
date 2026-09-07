/* 123. Best Time to Buy and Sell Stock III */
/* Runtime: 4ms, Memory: 79.30MB */

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Edge case: no price data means no profit possible
        if (prices.empty()) return 0;

        // State machine variables:
        // buy1 = max profit after 1st buy (negative value, i.e. cash spent)
        // sell1 = max profit after 1st sell
        // buy2 = max profit after 2nd buy
        // sell2 = max profit after 2nd sell (final answer)
        int buy1 = INT_MIN, sell1 = 0;
        int buy2 = INT_MIN, sell2 = 0;

        for (int p: prices) {
            // Update the states in order of transactions
            buy1 = max(buy1, -p);          // best (min) price to buy the 1st time
            sell1 = max(sell1, buy1 + p);  // best profit after 1st sell
            buy2 = max(buy2, sell1 - p);   // best profit after 2nd buy (reinvest 1st profit)
            sell2 = max(sell2, buy2 + p);  // best profit after 2nd sell
        }

        return sell2;
    }
};
