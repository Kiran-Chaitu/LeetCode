class Solution {
public:
    int heightChecker(vector<int>& heights) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        int n=heights.size(),c=0;
        vector<int> v(n);
        for(int i=0;i<n;i++)    v[i]=heights[i];
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++)    if(v[i]!=heights[i]) c++;
        return c;
    }
};