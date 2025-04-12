class Solution {
public:
    static bool compareStart(const vector<int>& a, const vector<int>& b){
        return a[0]<b[0];
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        int n =  intervals.size();

        vector<vector<int>> ans;

        sort(intervals.begin(),intervals.end(),compareStart);

        int start = intervals[0][0];
        int end = intervals[0][1];

        for(int i=1;i<n;i++){
            if(intervals[i][0]<=end){
                end = max(end, intervals[i][1]);
            }else{
                ans.push_back({start,end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }

        ans.push_back({start,end});
        return ans;
    }
};