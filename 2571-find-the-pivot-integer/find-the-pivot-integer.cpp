class Solution {
public:
    int pivotInteger(int n) {
        long long int lsum =(n*(n+1))/2 , rsum=n;
        while(n>0){
            if(lsum==rsum) return n;
            lsum-=n;
            n--;
            rsum+=n;
        }
        return -1;
    }
};