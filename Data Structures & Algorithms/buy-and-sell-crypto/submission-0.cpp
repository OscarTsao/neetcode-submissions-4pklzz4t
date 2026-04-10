class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minBuy = prices[0];
        int maxProfit = 0;

        for (const int& price : prices){
            maxProfit = max(maxProfit, price - minBuy);
            minBuy = min(minBuy, price);
        }
        return maxProfit;
    }
};
