class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int, int>, int> mp;
            int c=0;
            for(auto& i : dominoes){
                if(i[0] > i[1]) swap(i[0], i[1]);
                c+=mp[{i[0], i[1]}]++;
            }
            return c;
    }
};