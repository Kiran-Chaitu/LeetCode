class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int,vector<int>> mp;
        vector<int> v;
        int mini;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        for(auto i :queries ){
            int k = i;
            if(mp[nums[k]].size()==1){
                v.push_back(-1);
            }else{
                
                auto& t = mp[nums[k]];
                auto it = lower_bound(t.begin() , t.end() , k);
                int ind = it - t.begin();
                if(ind==0){
                    mini = min(t[1] - t[0] ,n - t[t.size()-1] + t[0] );
                }
                else if(ind == t.size()-1){
                    mini = min(n - t[t.size()-1] + t[0] , t[t.size()-1] - t[t.size()-2]);
                }else{
                    mini = min(t[ind+1] - t[ind] , t[ind] -t[ind-1] ); 
                }
                v.push_back(mini);
            }
        }
        return v;
    }
};