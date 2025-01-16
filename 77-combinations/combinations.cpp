class Solution {
public:
    void solve(int start, int n, int k, vector<int>& temp, vector<vector<int>>& result) {
        if (k == 0) {
            result.push_back(temp);
            return;
        }

        if (start > n) {
            return;
        }

        temp.push_back(start);
        solve(start + 1, n, k - 1, temp, result);

        temp.pop_back();
        solve(start + 1, n, k, temp, result);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        vector<vector<int>> result;
        solve(1, n, k, temp, result);
        return result;
    }
};
