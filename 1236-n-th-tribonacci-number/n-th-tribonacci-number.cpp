class Solution {
public:
int t[38];
    int tribo(int n, int t[]){
        if(t[n]!=-1){
            return t[n];
        }
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 1;

        return t[n] = tribo(n-1,t) + tribo(n-2,t) + tribo(n-3,t);
    }
    int tribonacci(int n) {
        memset(t,-1,sizeof(t));

        return tribo(n,t);
    }
};