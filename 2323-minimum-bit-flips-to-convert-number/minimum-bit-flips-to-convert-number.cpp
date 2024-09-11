class Solution {
public:
    int minBitFlips(int start, int goal) {
        int k = start ^ goal;
        int c = 0;
        while( k ){
            if( k & 1 == 1) c++;
            k = k >> 1;
        }
        return c;
    }
};