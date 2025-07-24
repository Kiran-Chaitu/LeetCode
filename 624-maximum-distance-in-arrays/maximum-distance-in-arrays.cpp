class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n=arrays.size();
        unordered_map<int,int> mini , maxi;
        for(int i=0;i<n;i++){
            int m = arrays[i].size()-1;
            if(mini.find(i)==mini.end()){
                mini[i] = arrays[i][0];
            }
            else mini[i] = min(mini[i] , arrays[i][0]);
            if(maxi.find(i) == maxi.end()){
                maxi[i] = arrays[i][m];
            }
            else maxi[i] = max(maxi[i] , arrays[i][m]);
        }
        vector<pair<int,int>> a(maxi.begin() , maxi.end()) , b(mini.begin() , mini.end());
        sort(a.begin() ,a.end() , [](pair<int,int> x , pair<int,int> y){
            return x.second > y.second;
        });
        sort(b.begin() ,b.end() , [](pair<int,int> x , pair<int,int> y){
            return x.second < y.second;
        });
        if(a[0].first!= b[0].first) return max(abs(a[0].second - b[0].second)  , abs(b[0].second - a[0].second));
        int fl = a[0].second , sl = a[1].second , fs = b[0].second , ss = b[1].second;
        int ans1 = max(abs(fl - ss) , abs(ss - fl));
        int ans2 = max(abs(sl - fs) , abs(fs - sl));
        // cout<<ans1<<" "<<ans2<<endl;
        return max(ans1 , ans2);
    }
};