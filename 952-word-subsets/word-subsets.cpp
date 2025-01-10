class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        vector<string> ans;
        unordered_map<char,int> mp;
        for(auto i: words2){
            unordered_map<char,int> temp;
            for(auto j : i){ 
                temp[j]++;
                if(mp[j]< temp[j]){
                    mp[j] = temp[j];
                    // cout<<mp[j]<<" "<<j<<endl;
                }
            }
        }
        for(auto i:words1){
            unordered_map<char,int> temp;
            for(auto j:i) temp[j]++;
            int c=0;
            for(auto k : mp){
                if(mp[k.first] <= temp[k.first]) c++;
                // cout<<mp[k.first] <<" "<<temp[k.first]<<" k.first ="<<k.first<<endl;
            }
            //cout<<"size = "<<mp.size()<<endl;
            if(c == mp.size())  ans.push_back(i);
            // cout<<endl;
        }
        return ans;
    }
};