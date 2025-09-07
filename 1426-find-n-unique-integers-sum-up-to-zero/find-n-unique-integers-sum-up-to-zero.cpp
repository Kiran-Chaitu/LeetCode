class Solution {
public:
    vector<int> sumZero(int n) {
        if(n==1) return {0};
        int temp = n;
        n/=2;
        vector<int> ans;
        while(n > 0 ) {
            ans.push_back(n);
            ans.push_back(-n);
            n--;
        }
        if(temp&1) ans.push_back(0);
        return ans;
    }
};