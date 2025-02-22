class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;

        int i = 0, j = n - 1;
        int a = -1, b = -1; 

        //finding the first ocurrence
        while (i <= j) {
            int mid = i + (j - i) / 2;
            if (nums[mid] >= target) {
                j = mid - 1;  // move continuously towards left
            } else {
                i = mid + 1;
            }
        }
        if (i < n && nums[i] == target) {
            a = i; 
        } else {
            return {-1, -1}; 
        }

        //finding the Last ocurrence
        j = n - 1; 
        while (i <= j) {
            int mid = i + (j - i) / 2;
            if (nums[mid] <= target) {
                i = mid + 1; // move continuously towards right
            } else {
                j = mid - 1;
            }
        }
        b = j; 

        return {a, b};
    }
};
