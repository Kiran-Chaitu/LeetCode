class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int,vector<int>> m;
        for(int i=0;i<groupSizes.size();i++){
            m[groupSizes[i]].push_back(i);
        }
        vector<vector<int>> v;
        for(auto i:m){
            int j=0;
            vector<int>temp=i.second;
            while(j<temp.size()){
                vector<int>res;
                for(int k=0;k<i.first;k++){
                    res.push_back(temp[k+j]);
                }
                v.push_back(res);
                j+=i.first;
            }
        }
        return v;
    }
};