class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;
        if(n==0){
            return ans;
        }

        vector<int > v(arr);
        sort(v.begin(),v.end());


        vector<int > r(n);
        r[0] = 1;

        unordered_map<int, int> ranks;
        int rank = 1;
        
        for(int i = 0; i < n; i++) {
            if(ranks.find(v[i]) == ranks.end()) {
                ranks[v[i]] = rank++;
            }
        }

        for(int i = 0; i < n; i++) {
            ans.push_back(ranks[arr[i]]);
        }

        return ans;
    }
};