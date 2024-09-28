class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int num = 0;
        int ans = INT_MIN;
        int j = 0;
        for(int i=0;i<n;i++){
            while((nums[i] & num) !=0){ // problem
                num = num ^nums[j];
                j++; // xor karne se joh bits humne set ki thi woh nikal sakte hai
            }

            num = num | nums[i]; // OR karne se hum ek num number mein saare bits ko add kar rahe hai jinka AND zero hai
            ans = max(ans,i-j+1);
        }

        return ans;
    }
};