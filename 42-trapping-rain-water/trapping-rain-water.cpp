class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int v1[n];

        v1[0] = height[0];
        int max = height[0];
        for(int i=1;i<n;i++){
            if(height[i]>max){
                max = height[i];
            }
            v1[i] = max;
        }

        int v2[n];
        v2[n-1] = height[n-1];
        max = height[n-1]; 
        for(int i=n-2;i>=0;i--){
            if(height[i]>max){
                max = height[i];
            }
            v2[i] = max;
        } 

        int v3[n];
        for(int i=0;i<n;i++){
            int k = min(v1[i],v2[i]);
            v3[i] = k;
        }

        int sum = 0;
        for(int i=0;i<n;i++){
            sum = sum + (v3[i] - height[i]);
        }

        return sum;
    }
};