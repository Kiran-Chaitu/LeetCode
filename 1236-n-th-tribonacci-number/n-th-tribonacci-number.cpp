class Solution {
public:
    int tribonacci(int n) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        int a=0,b=1,c=1;
        int d=a+b+c;
        if(n==0) return 0;
        else if(n==1) return 1;
        else if(n==2) return 1;
        else if(n==3) return 2;
        n-=3;
        while(n--){
            a=b;
            b=c;
            c=d;
            d=a+b+c;
        }
        return d;
    }
};