class Solution {
public:
    bool isPalindrome(string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int solve(string& s, int i, int j, vector<vector<int>>& dp) {
        if (isPalindrome(s, i, j)) {
            return 0; 
        }

        if (dp[i][j] != -1) return dp[i][j]; 

        int result = INT_MAX;

        for (int k = i; k < j; k++) {
            if (isPalindrome(s, i, k)) { 
                int temp = 1 + solve(s, k + 1, j, dp);
                result = min(result, temp);
            }
        }

        return dp[i][j] = result;
    }
    int minCut(string s) {
        int n = s.length();

        int i=0;
        int j=n-1;

        vector<vector<int>> dp(n, vector<int>(n, -1)); 
        return solve(s, i, j, dp);
        
    }
};