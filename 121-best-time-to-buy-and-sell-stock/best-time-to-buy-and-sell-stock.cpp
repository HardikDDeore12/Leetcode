class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int minimum = prices[0];
        int maxProfit = 0;

        for(int i=1;i<n;i++){
            int currProfit = prices[i] - minimum;
            maxProfit = max(maxProfit,currProfit);
            minimum = min(prices[i],minimum);
        }

        return maxProfit;
    }
};