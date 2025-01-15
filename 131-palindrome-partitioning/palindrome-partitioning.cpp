class Solution {
public:
    void solve(string& s, int i, vector<string>& currPartition, vector<vector<bool>>& t, vector<vector<string>>& result) {
        if (i == s.length()) {
            result.push_back(currPartition);
            return;
        }

        for (int j = i; j < s.length(); j++) {
            if (t[i][j]) { // if the substring s[i..j] is a palindrome
                currPartition.push_back(s.substr(i, j - i + 1));
                solve(s, j + 1, currPartition, t, result);
                currPartition.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<bool>> t(n, vector<bool>(n, false));

        // Initialize the DP table
        for (int i = 0; i < n; i++) {
            t[i][i] = true; // Single character substrings are palindromic
        }

        for (int L = 2; L <= n; L++) {
            for (int i = 0; i + L - 1 < n; i++) {
                int j = i + L - 1;

                if (s[i] == s[j]) {
                    if (L == 2) {
                        t[i][j] = true; // Two-character palindromes
                    } else {
                        t[i][j] = t[i + 1][j - 1]; // Check the inner substring
                    }
                }
            }
        }

        vector<vector<string>> result;
        vector<string> currPartition;
        solve(s, 0, currPartition, t, result);

        return result;
    }
};
