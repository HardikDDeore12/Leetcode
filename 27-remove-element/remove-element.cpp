class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int count=0;

        for(int i=0;i<n;i++){
            if(nums[i] == val){
                count++;
                nums[i] = 51;
            }
        }
        int k = n-count;
        sort(nums.begin(),nums.end());
        return k;
    }
};