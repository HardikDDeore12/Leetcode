class Solution {
public:
    int helper(int i, int n, vector<int>& nums, vector<int>& dp) {
        if (i >= n - 1) return 0;  // Base case: Reached or exceeded the last index
        if (dp[i] != -1) return dp[i];  // Use cached result if available

        int mini = INT_MAX;
        for (int j = 1; j <= nums[i]; j++) {  // Explore all possible jumps
            int nextJump = helper(i + j, n, nums, dp);
            if (nextJump != INT_MAX) {  // Only add 1 if the next jump is valid
                mini = min(mini, 1 + nextJump);
            }
        }

        return dp[i] = mini;  // Cache the result
    }

    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);  // Initialize memoization array
        return helper(0, n, nums, dp);  // Start from the first index
    }
};
