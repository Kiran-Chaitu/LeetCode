class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,int> mp;
        for(int i=0;i<list1.size();i++) mp[list1[i]]=i;
        int dif=INT_MAX;
        for(int i=0;i<list2.size();i++){
            if(mp.find(list2[i])!=mp.end()){
                if(dif > (i + mp[list2[i]] )) dif = (i + mp[list2[i]] );
            }
        }
        vector<string> v;
        for(int i=0;i<list2.size();i++){
            if(mp.find(list2[i])!=mp.end()){
                if(dif == (i + mp[list2[i]] )) v.push_back(list2[i]);
            }
        }
        return v;
    }
};