class Solution {
public:
    bool isNonZero(int n){
        while(n){
            if(n%10 == 0 ) return false;
            n/=10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        for(int i = n-1 ; i >=1;i--){
            if(isNonZero(i) and isNonZero(n-i)) return {n-i , i};
        }
        return {};
    }
};