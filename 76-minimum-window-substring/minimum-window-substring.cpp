class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();

        if (m > n) return ""; // If t is longer than s, no valid window exists.

        unordered_map<char, int> mp; 
        for (char c : t) {
            mp[c]++;
        }

        int count = mp.size(); 
        int minLen = INT_MAX; 
        int start = 0;

        int l = 0, r = 0; 

        while (r < n) {
            if (mp.find(s[r]) != mp.end()) {
                mp[s[r]]--;
                if (mp[s[r]] == 0) {
                    count--;
                }
            }

            while (count == 0) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }

                if (mp.find(s[l]) != mp.end()) {
                    mp[s[l]]++;
                    if (mp[s[l]] > 0) {
                        count++; 
                    }
                }
                l++;
            }

            r++; 
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
