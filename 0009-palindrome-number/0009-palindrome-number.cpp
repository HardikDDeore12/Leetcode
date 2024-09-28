class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false; 
        } else {
            int original = x; 
            long long num = 0;
            int a = 0;
            
            while (x > 0) {
                a = x % 10;
                num = num * 10 + a;
                x = x / 10;
            }

            return num == original; 
        }
    }
};
