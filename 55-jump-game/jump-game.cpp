class Solution {
public:
    bool helper(int i, vector<int>& nums,vector<int>& dp){
        if(i == nums.size()-1) return dp[i]=true;
        if(dp[i] != -1) return dp[i];
        for(int j=1;j<=nums[i];j++){
            if(helper(i+j,nums,dp) == true) return dp[i]=true;
        }
        return dp[i]=false;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);
        int i=0;
        return helper(i,nums,dp);
    }
};