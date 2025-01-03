class Solution {
public:
    int helper(int i,int n,vector<int>& nums,vector<int>& dp){
        if(i>=n) return 0;
        if(dp[i] != -1) return dp[i];

        int steal = nums[i] + helper(i+2,n,nums,dp);
        int skip = helper(i+1,n,nums,dp);

        return dp[i]=max(steal,skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];  

        // Case 1: Rob houses from index 0 to n-2
        vector<int> dp(n, -1);
        int case1 = helper(0, n - 1, nums, dp);

        // Case 2: Rob houses from index 1 to n-1
        dp.assign(n, -1);  // Reinitialize dp
        int case2 = helper(1, n, nums, dp);

        return max(case1, case2);  // Return the maximum of both cases
    }
};