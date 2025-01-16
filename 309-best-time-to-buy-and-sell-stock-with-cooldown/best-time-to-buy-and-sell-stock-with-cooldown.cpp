class Solution {
public:
    int solve(int index, int buy, int n, vector<int>& prices, vector<vector<int>>& t) {
        if (index >= n) return 0;
        if (t[index][buy] != -1) return t[index][buy]; 

        int profit = 0;

        if (buy) {
            profit = max(
                -prices[index] + solve(index + 1, 0, n, prices, t), // Buy stock
                solve(index + 1, 1, n, prices, t) // Skip buying
            );
        } else {
            profit = max(
                prices[index] + solve(index + 2, 1, n, prices, t), // Sell stock
                solve(index + 1, 0, n, prices, t) // Skip selling
            );
        }

        return t[index][buy] = profit; 
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> t(n, vector<int>(2, -1)); 
        return solve(0, 1, n, prices, t); 
    }
};
