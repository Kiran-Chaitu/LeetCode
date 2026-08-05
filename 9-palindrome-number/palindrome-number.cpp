class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int n=x;
        long long rev=0;
        while(x>0){
            int rm=x%10;
            rev=rev*10+rm;
            x/=10;
        }
        if(rev == n) return true;
        return false;
    }
};