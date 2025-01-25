class Solution {
public:
    long long solve(vector<int>& nums, vector<int>& cost, int mid, int n) {
        long long total_cost = 0; 
        for (int i = 0; i < n; i++) {
            total_cost += (long long)(abs(nums[i] - mid)) * cost[i];
        }
        return total_cost;
    }

    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();

        int l = 1;
        int r = *max_element(begin(nums), end(nums));
        long long answer = LLONG_MAX; 

        while (l <= r) {
            int mid = l + (r - l) / 2;

            long long a = solve(nums, cost, mid, n);
            long long b = solve(nums, cost, mid + 1, n);

            answer = min(answer, a);

            if (a <= b) {
                r = mid - 1; 
            } else {
                l = mid + 1; 
            }
        }

        return answer;
    }
};
