class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string s="";
        for(auto i : words){
            int w = 0;
            for(auto j : i){
                w += (weights[j - 'a']);
            }
            w%=26;
            s+= ('z' - w);
        }
        return s;
    }
};