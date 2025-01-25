class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        // We will use Binary Search
        int n= time.size();
        long long min_time = INT_MAX;
        for(int i=0;i<n;i++){
            if(time[i]<min_time){
                min_time = time[i];
            }
        }

        long long l = 1;
        long long r = min_time * (long long)totalTrips;



        while(l<r){
            long long mid = l+ (r-l)/2;
            long long trips=0;

            for(int i=0;i<n;i++){
                trips = trips + mid/time[i];
            }

            if(trips>=totalTrips){
                r=mid;
            }else{
                l=mid+1;
            }
        }

        return l;
    }
};