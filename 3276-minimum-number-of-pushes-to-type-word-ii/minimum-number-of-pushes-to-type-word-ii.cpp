class Solution {
public:
    int minimumPushes(string word) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        unordered_map<char,int> mp;
        for(int i=0;i<word.size();i++){
            mp[word[i]]++;
        }
        vector<pair<char,int>> vec(mp.begin(),mp.end());
        sort(vec.begin(),vec.end(),[](pair<char,int> &a,pair<char,int> &b){
            return a.second > b.second;
        });
        int ans=0;
        for(int i=0;i<vec.size();i++){
            float temp = i;
            ans+=(vec[i].second*ceil((temp+1)/8));
            //cout<<ans<<" "<<vec[i].second<<" "<<ceil(temp+1/8)<<endl;

        }
        return ans;
    }
};