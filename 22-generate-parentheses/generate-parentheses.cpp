class Solution {
public:
    void solver(int c,int o,string s,int n,vector<string> &v){
        if(c+o >= n*2){
            v.push_back(s);
            return;
        }
        if(c > o) return;
        if(o==n) solver(c+1,o,s+')',n,v);
        else{
            solver(c,o+1,s+'(',n,v);
            solver(c+1,o,s+')',n,v);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        solver(0,1,"(",n,v);
        return v;
    }
};