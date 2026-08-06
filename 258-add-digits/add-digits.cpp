class Solution {
public:

    int digit_sum(int n){
        int sum = 0;
        while( n > 0){
            int digit = n %10;
            sum  = sum + digit;
            n = n/10;
        }
        return sum;
    }
    int addDigits(int num) {
        while( num > 9){
            int result = digit_sum(num);
            num = result;
        }
        return num;
    }
};