class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int a =  n  , b = n , k  =1 , os=0,es=0;
        while(a>0){
            os+=k;
            a--;
        }
        k=2;
        while(b>0){
            es+=k;
            b--;
        }
        return __gcd(os,es);
    }
};