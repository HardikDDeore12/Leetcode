class Solution {
public:

static bool check(string &s1, string &s2){
    return (s1+s2)>=(s2+s1);
}


    string largestNumber(vector<int>& nums) {
        int x = 0;
        int n = nums.size();

        for(int i=0;i<n;i++){
            if(nums[i] == 0){
                x++;
            }
        }

        if(x == n){
            return "0";
        }
        // string declaration using vector
        vector<string> s(n,"");

        // converted all the integer elements to string
        for(int i=0;i<n;i++){
            s[i]= to_string(nums[i]);
        }

        sort(s.begin(), s.end(), check);

        string ans = "";
        for(int i=0;i<n;i++){
            ans+=(s[i]);
        }

        return ans;
    }
};