
class Solution {
public:
    int maximumSwap(int n) {
        vector<int> v;
        while(n > 0){
            int digit = n % 10;
            v.push_back(digit);
            n /= 10;
        }
        
        reverse(v.begin(), v.end());

        vector<int> ans = v;
        sort(ans.begin(), ans.end(), std::greater<int>());

        for(int i = 0; i < v.size(); i++) {
            if(ans[i] != v[i]) {
                int max_digit = ans[i];
                int mx_id = -1;

                for(int j = v.size() - 1; j >= i; j--) {
                    if(v[j] == max_digit) {
                        mx_id = j;
                        break;
                    }
                }

                swap(v[i], v[mx_id]);

                int num = 0;
                for (int digit : v) {
                    num = num * 10 + digit;
                }
                return num;
            }
        }

        int num = 0;
        for (int digit : v) {
            num = num * 10 + digit;
        }
        return num;
    }
};