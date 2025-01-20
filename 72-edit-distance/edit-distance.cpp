class Solution {
public:
    int t[501][501];
    int solve(string& s1, string& s2, int i, int j){
        int m = s1.length();
        int n = s2.length();

        if(t[i][j] != -1){
            return t[i][j];
        }

        if(i == m){
            return n-j; //insertions
        }else if(j == n){
            return m-i; //deletions
        }

        if(s1[i] == s2[j]){
            return t[i][j] = solve(s1,s2,i+1,j+1);
        }

        int Insert = 1 + solve(s1,s2,i,j+1);
        int Delete = 1 + solve(s1,s2,i+1,j);
        int Replace = 1 + solve(s1,s2,i+1,j+1);

        return t[i][j] = min({Insert, Delete, Replace});
    }
    int minDistance(string s1, string s2) {
        memset(t,-1,sizeof(t));
        return solve(s1,s2,0,0);
    }
    
};