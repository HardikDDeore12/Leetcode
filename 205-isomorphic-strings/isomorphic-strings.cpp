class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m = s.length();
        int n = t.length();

        if (m != n) {
            return false;
        }

        unordered_map<char, char> mp1; // Mapping for s -> t
        unordered_map<char, char> mp2; // Mapping for t -> s

        for (int i = 0; i < m; i++) {
            char ch1 = s[i];
            char ch2 = t[i];

            if (mp1.count(ch1) && mp1[ch1] != ch2) {
                return false;
            }

            if (mp2.count(ch2) && mp2[ch2] != ch1) {
                return false;
            }

            mp1[ch1] = ch2;
            mp2[ch2] = ch1;
        }

        return true;
    }
};



//container.count(key)
//container: The container in which you are searching.
//key: The value you are checking for existence.