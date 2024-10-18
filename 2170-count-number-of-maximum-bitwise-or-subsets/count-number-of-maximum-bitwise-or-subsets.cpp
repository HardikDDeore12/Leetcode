class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int mx = 0;  
        int count = 0;

//there are 2^n subset... and each subset can be represented in i
//for eg i = 5, 101 include first element, exclude second element, include third element
        for (int i = 0; i < (1 << n); i++) {  
            int z = 0;

            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    z = z | nums[j];
                }
            }

            if (z > mx) {
                mx = z;
                count = 1;  
            } else if (z == mx) {
                count++;  
            }
        }

        return count;
    }
};
