class Solution {
public:
    int getSum(int a, int b) {
        while(b){
            int c = a&b;
            a = a^b;
            b = c<<1;
        }
        return a;
    }
};