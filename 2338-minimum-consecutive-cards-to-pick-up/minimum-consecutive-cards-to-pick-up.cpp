class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        int n=cards.size(),k=-1;
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[cards[i]].push_back(i);
        }
        int mini= INT_MAX;
        for(auto i:mp){
            if(i.second.size() >1){
                k=1;
                for(int j=0;j<i.second.size()-1;j++){
                    mini = min(mini, i.second[j+1] - i.second[j]);
                }
            }
        }
        return (k==-1)?-1:mini+1;
    }
};