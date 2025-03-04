class Solution {
public:
    int helper(int i,int j, int m, int n, vector<vector<int>>& arr,vector<vector<int>>& dp){
        if(i>=m || j>=n || arr[i][j]== 1) return 0;
        if(i == m-1 && j == n-1) return 1; 
        if(dp[i][j] != -1) return dp[i][j];

        int a = helper(i+1,j,m,n,arr,dp);
        int b = helper(i,j+1,m,n,arr,dp);

        return dp[i][j] = a+b;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int m = arr.size();
        int n = arr[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int i = 0;
        int j = 0;
        return helper(i,j,m,n,arr,dp);
    }
};