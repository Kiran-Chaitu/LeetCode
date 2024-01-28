class Solution {
public:
    int trap(vector<int>& height) {
        vector <int> l , r;
        int maxi = 0, n = height.size();
        for(int i = 0 ; i < n ; i++) {
            if( height[ i ] > maxi ) maxi = height[i];
            l.push_back( maxi );
        }
        maxi = 0 ;
        for(int i = n - 1 ; i >= 0 ; i--) {
            if( height[i] > maxi ) maxi = height[i];
            r.push_back( maxi );
        }
        int sum = 0;
        for(int i = 0 ; i < n ; i++ ) {
            int ans = ( min( l[i] , r[n-i-1] ) ) - height[i];
            sum += ans;
        }
        return sum;
    }
};