class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int profit = 0;

        for (int x : prices) {
            minPrice = min(minPrice, x);
            profit = max(profit, x-minPrice);
        }
        return profit;
    }
};
