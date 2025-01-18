class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        // cumulative sum row wise
        for (int row = 0; row < m; row++) {
            for (int col = 1; col < n; col++) {
                matrix[row][col] += matrix[row][col - 1];
            }
        }

        int count = 0;
        // now find the no of subarrays having sum == target (leetcode-560)
        for (int startCols = 0; startCols < n; startCols++) {
            for (int j = startCols; j < n; j++) {
                unordered_map<int, int> mp;
                mp.insert({0,1});
                int Cum_sum = 0;

                for (int row = 0; row < m; row++) {
                    Cum_sum += matrix[row][j] - (startCols > 0 ? matrix[row][startCols - 1] : 0);

                    if(mp.find(Cum_sum - target) != mp.end()){
                        count += mp[Cum_sum - target];
                    }
                
                    mp[Cum_sum]++;
                }
            }
        }

        return count;
    }
};



