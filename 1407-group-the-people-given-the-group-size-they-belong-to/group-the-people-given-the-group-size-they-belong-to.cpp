class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int,vector<int>> m;
        int n=groupSizes.size();
        for(int i=0;i<n;i++){
            m[groupSizes[i]].push_back(i);
        }
        vector<vector<int>> ans;
        for(auto i:m){
            n=i.first;
            vector<int> dum;
            int c=1;
            for(int j=0;j<i.second.size();j++){
                dum.push_back(i.second[j]);
                if(c==n){
                    ans.push_back(dum);
                    dum.clear();
                    c=1;
                }
                else{
                    c++;
                }
            }
        }
        return ans;
    }
};