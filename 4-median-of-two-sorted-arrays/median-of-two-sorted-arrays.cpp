class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        int i=0;
        int j=0;
        int k=0;

        double element1 , element2 =0;
        int size = m+n;
        int idx1 = (size/2)-1;
        int idx2 = (size/2);

        while(i<m && j<n){
            if(nums1[i]<=nums2[j]){
                if(k == idx1){
                    element1 = nums1[i];
                }
                if(k == idx2){
                    element2 = nums1[i];
                }
                i++;
                k++;
            }else{
                if(k == idx1){
                    element1 = nums2[j];
                }
                if(k == idx2){
                    element2 = nums2[j];
                }
                j++;
                k++;
            }
        }

        while(i!=m){
            if(k == idx1){
                    element1 = nums1[i];
                }
                if(k == idx2){
                    element2 = nums1[i];
                }
            i++;
            k++;
        }

        while(j!=n){
            if(k == idx1){
                    element1 = nums2[j];
                }
                if(k == idx2){
                    element2 = nums2[j];
                }
                j++;
                k++;
        }

        
        if(size%2 == 0){
            return (element1+element2)/2;
        }else{
            return element2;
        }
        return 0;
    }
};