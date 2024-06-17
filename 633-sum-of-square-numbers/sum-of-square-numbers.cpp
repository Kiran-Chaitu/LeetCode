class Solution {
public:
    bool judgeSquareSum(int c) {
        long long int i=0,j=sqrt(c);
        while(i<=j){
            long long int val = (i*i)+(j*j);
            if(val==c) return true;
            else if(val > c) j--;
            else i++;
        }
        return false;

    }
};