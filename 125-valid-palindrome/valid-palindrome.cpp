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

        for(int i=0;i<n;i++){
            int ch = s[i];

            if(ch>=65 && ch<=90){ 
                ne.push_back(s[i] + 32);
            }else if(ch>=97 && ch<=122){
                ne.push_back(s[i]);
            }else if(ch >= 48 && ch <= 57){
                ne.push_back(s[i]);
            }
        }

        return check(ne,0,ne.length()-1);
    }
};