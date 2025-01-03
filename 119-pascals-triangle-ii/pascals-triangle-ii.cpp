class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> ans;
        int n = rowIndex+1 ;

        for (int i=0; i<n; i++) {
            vector<int> v;  
            for (int j=0;j<=i;j++) {
                if (j==0 || j==i) 
                    v.push_back(1);  
                else 
                    v.push_back(ans[i-1][j-1] + ans[i-1][j]);  
            }
            ans.push_back(v);  
        }

        return ans[rowIndex];
    }
};