class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        int flag =-1;

        unordered_map<int,int> map;

        for(int i=0;i<n;i++){
            if(map.find(nums[i]) != map.end()){
                int check = abs(map[nums[i]]-i);
                if(check <= k){
                    flag = 1;
                }
            }
            map[nums[i]] = i;
        }

        if(flag == 1){
            return true;
        }

        return false;
    }
};