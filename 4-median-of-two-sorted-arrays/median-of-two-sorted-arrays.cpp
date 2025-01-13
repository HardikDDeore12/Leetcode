class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        vector<double> v;
        int i=0;
        int j=0;

        while(i<m && j<n){
            if(nums1[i]<=nums2[j]){
                v.push_back(nums1[i]);
                i++;
            }else{
                v.push_back(nums2[j]);
                j++;
            }
        }

        while(i!=m){
            v.push_back(nums1[i]);
            i++;
        }

        while(j!=n){
            v.push_back(nums2[j]);
            j++;
        }

        int size = v.size();
        if(size%2 == 0){
            int a = size/2;
            int b = a-1;
            return (v[a] + v[b])/2;
        }else{
            int a = size/2;
            return v[a];
        }
        return 0;
    }
};