class Solution {
public:
    int smallestNumber(int n) {
        long long base = 2 , exp = 1;
        while(pow(base , exp) <= n){
            exp++;
        }
        return pow(base,exp)-1;
    }
};