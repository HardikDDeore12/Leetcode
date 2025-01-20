class Solution {
public:
    bool check(string &s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    bool isPalindrome(string s) {
        int n = s.length();
        string ne = "";

        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (isalnum(ch)) { 
                ne.push_back(tolower(ch)); // Convert to lowercase
            }
        }
        
        return check(ne, 0, ne.length() - 1);
    }
};
