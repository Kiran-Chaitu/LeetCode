class Solution {
public:
    int product(int n){
        int pro =1;
        while(n > 0){
            pro *= (n%10);
            n /= 10;
        }
        return pro;
    }
    int smallestNumber(int n, int t) {
        
        while( product(n) % t != 0) {
            n++;
        }
        return n;
    }
};