class Solution {
public:
    vector<vector<int>> result;
    void solve(int i, int n, int count, vector<int>& nums, int target, vector<int>& temp){
        if(count == target){
            result.push_back(temp);
            return;
        }

        if(i>=n ||count>target){
            return;
        }

        temp.push_back(nums[i]);
        solve(i,n,count+nums[i],nums,target,temp);

        temp.pop_back();
        solve(i+1,n,count,nums,target,temp);

    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> temp;
        int count = 0;
        solve(0,n,count,nums,target,temp);
        return result;
    }
};