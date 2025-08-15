
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0) return false;
        if(n == 1) return true;
       int l = log2(n) + 1,c = 0;

       while(n) {
           if( (n & 1 ) == 1 ) c++;
           n=n>>1;
       }
       return ( l % 2 == 1) and (c == 1); 
    }
};