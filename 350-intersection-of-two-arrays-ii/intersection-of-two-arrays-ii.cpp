class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        vector<int> ans;

        unordered_map<int,int> map1;
        unordered_map<int,int> map2;

        for(int i=0;i<n;i++){
            map1[nums1[i]]++;
        }

        for(int i=0;i<m;i++){
            map2[nums2[i]]++;
        }


        for(auto it=map1.begin();it!=map1.end();it++){
            if(map2.find(it->first) != map2.end()){
                int count = min(it->second,map2[it->first]);
                while(count!=0){
                    ans.push_back(it->first);
                    count--;
                }
            }
        }

        return ans;
    }
};