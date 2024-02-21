class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int x=0;
        while( left !=right){
            left>>=1;
            right>>=1;
            x+=1;
        }
        return left<<x;
    }
};