class Solution {
public:
    vector<vector<int>> result;

    void solve(int i, int n, vector<int>& nums) {
        if (i >= n) {
            result.push_back(nums);
            return;
        }

        for (int j = i; j < n; j++) {
            swap(nums[i], nums[j]); // swapping is done to generate all permutations
            solve(i + 1, n, nums);
            swap(nums[i], nums[j]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        solve(0, n, nums);
        return result;
    }
};
