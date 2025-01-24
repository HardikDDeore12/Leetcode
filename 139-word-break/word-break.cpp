class Solution {
public:
    unordered_set<string> st; // Set to store words from the dictionary
    int t[301];              

    bool solve(int idx, string& s) {
        if (idx >= s.length()) { 
            return true;
        }

        if (t[idx] != -1) { 
            return t[idx];
        }

        for (int l = 1; l <= s.length() - idx; l++) {
            string temp = s.substr(idx, l); 

            if (st.find(temp) != st.end() && solve(idx + l, s)) { 
                return t[idx] = true;
            }
        }

        return t[idx] = false; 
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        memset(t, -1, sizeof(t)); 

        for (const string& word : wordDict) { 
            st.insert(word);
        }

        return solve(0, s); 
    }
};
