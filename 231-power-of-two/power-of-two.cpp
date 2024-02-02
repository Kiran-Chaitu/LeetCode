class Solution {
public:
    bool is2(int n,long long i){
        if(i>n) return false;
        if(i==n) return true;
        return is2(n,i*2);
    }
    bool isPowerOfTwo(int n) {
        if(n==1) return true;
        if(n==0) return false;
        return is2(n,1);
    }
};