class Solution {
public:
    int findMinimum(vector<int>& nums){
        int i = 0;
        int j = nums.size() - 1;

        while(i<j && nums[i] == nums[i+1]){  // this removes duplicates
            i++;
        }

        while(i<j && nums[j] == nums[j-1]){  // this removes duplicates
            j--;
        }

        while(i<j){
            int mid = i + (j-i)/2;

            if(nums[mid]>=nums[j]){
                i = mid+1;
            }else{
                j =mid;
            }
        }

        return i;
    }

    int binarySearch(vector<int>&nums, int i, int j, int target){
        int index = -1;

        while(i<=j){
            int mid = i + (j-i)/2;

            if(nums[mid] == target){
                index = mid;
                break;
            }else if(nums[mid]>target){
                j = mid-1;
            }else{
                i = mid+1;
            }
        }

        return index;
    }
     
    bool search(vector<int>& nums, int target) {
        int pivot = findMinimum(nums);
        
        int index = binarySearch(nums, 0, pivot-1, target); // binary search in the left portion

        if(index != -1){
            return true;
        }

        index = binarySearch(nums, pivot, nums.size()-1, target); // binary search in the right portion
        
        if(index != -1){
            return true;
        }

        return false;
    }
};