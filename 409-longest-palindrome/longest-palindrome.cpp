class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;

        for (char ch : s) {
            mp[ch]++;
        }

        int count = 0;

        for (auto& pair : mp) { 
            if (pair.second % 2 == 0) {
                count += pair.second; 
                pair.second = 0;   
            } else {
                if (pair.second > 1) {
                    count += pair.second - 1; 
                    pair.second = 1;        
                }
            }
        }

        for (auto& pair : mp) {
            if (pair.second != 0) {
                count++; 
                break;   
            }
        }

        return count;
    }
};
