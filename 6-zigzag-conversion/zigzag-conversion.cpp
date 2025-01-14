class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length();
        if(numRows == 1) return s;
        string result = "";

        int jumps = (numRows-1)*2;

        for(int i=0;i<numRows;i++){
            for(int j=i;j<n;j+=jumps){
                result = result + s[j];

                if(i>0 && i<numRows-1 && (j+jumps-2*i)<n){
                    result = result + s[j+jumps-2*i];
                }
            }
        }
        
        return result;
    }
};