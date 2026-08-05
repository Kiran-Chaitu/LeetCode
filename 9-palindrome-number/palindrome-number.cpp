class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        long long rev = 0 , org = x;
        while(x > 0){
            int digit = x%10;
            rev = rev * 10 + digit;
            x  =x /10;
        }
        if(rev == org) return true;
        return false;
    }
};