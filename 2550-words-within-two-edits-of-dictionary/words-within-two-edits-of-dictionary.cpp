class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        unordered_map<string , int> ump , temp;
        for(auto i : dictionary){
            ump[i] = 1;
        }
        vector<string> ans;
        for(auto i : queries){
            string str = i;
            for(auto j : dictionary){
                int cnt = 0;
                if(i.size()!=j.size()) continue;
                for(int k = 0;k<i.size();k++){
                    if(i[k]!=j[k]){
                        cnt++;
                        if(cnt>2) break;
                    }
                }
                if(cnt <=2) temp[str]=1;
            }
        }
        for(auto i : queries){
            if(temp.find(i)!=temp.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};