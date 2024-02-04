class Solution {
public:
    set<vector<int>> st;
    void solver(vector<int> s, int start, int end){
        if (start >= end){
            st.insert(s);
            return;
        } 
        for(int i=start;i<=end;i++){
            swap(s[start],s[i]);
            solver(s,start+1,end);
            swap(s[start],s[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> v;
        solver(nums,0,nums.size()-1);
        for(auto i: st){
            v.push_back(i);
        }
        return v;
    }
};