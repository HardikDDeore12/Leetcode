class Solution {
public:
    int divideAndConquer(const string &s, int start, int end, int k) {
        if (end - start < k) return 0;  

        unordered_map<char, int> freq;
        for (int i = start; i < end; i++) {
            freq[s[i]]++;
        }

        for (int mid = start; mid < end; mid++) {
            if (freq[s[mid]] < k) {  
                int left = divideAndConquer(s, start, mid, k);
                int right = divideAndConquer(s, mid + 1, end, k);
                return max(left, right);
            }
        }

        return end - start;
    }
    
    int longestSubstring(string s, int k) {
        return divideAndConquer(s, 0, s.size(), k);
    }
};
