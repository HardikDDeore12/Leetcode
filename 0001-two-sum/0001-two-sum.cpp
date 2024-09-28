class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> v;
        unordered_map<int,int> map;

        for(int i=0;i<n;i++){
            int k = target - nums[i];
            if(map.find(k) != map.end()){
                v.push_back(i);
                v.push_back(map[k]);
                return v;
            }
            else{
                map[nums[i]] = i;
            }
        }
        return {-1,-1};
    }
};