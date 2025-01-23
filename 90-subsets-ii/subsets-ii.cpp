class Solution {
public:
    void solve(vector<int>& nums, int i, vector<int>& temp, vector<vector<int>>& ans){
        if(i>=nums.size()){
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[i]); // take
        solve(nums,i+1,temp,ans);

        temp.pop_back(); // not take
        // while(i<nums.size() && nums[i] == nums[i-1]){  gives error when i=0
        //     i++;
        // }

        while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
            i++;
        }

        solve(nums,i+1,temp,ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;

        vector<int> temp;
        sort(nums.begin(),nums.end());

        solve(nums, 0, temp, ans);

        return ans;
    }
};