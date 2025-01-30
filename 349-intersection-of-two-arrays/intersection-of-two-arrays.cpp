class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n =nums1.size();
        int m =nums2.size();

        vector<int> ans;

        set<int> set1;
        set<int> set2;

        set1.insert(nums1.begin(),nums1.end());
        set2.insert(nums2.begin(),nums2.end());

        for (int num1 : set1) {
            for (int num2 : set2) {
                if(num1 == num2){
                    ans.push_back(num1);
                }
            }
        }

        return ans;
        
    }
};