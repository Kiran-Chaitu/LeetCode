class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> ls,rs;
        int lf=0,rm=0,ans=0,n=height.size();
        for(int i=0;i<n;i++){
            if(lf<height[i]) lf=height[i];
            ls.push_back(lf);
        }
        for(int i=n-1;i>=0;i--){
            if(rm<height[i]) rm=height[i];
            rs.push_back(rm);
        }
        for(int i=0;i<n;i++){
            ans+= (min(ls[i],rs[n-i-1])) - height[i];
        }
        return ans;
    }
};