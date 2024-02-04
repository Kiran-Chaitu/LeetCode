
class Solution {
public:
    vector<vector<int>> v;
    void solver(vector<int> s, int start, int end){
        if (start >= end){
            v.push_back(s);
            return;
        } 
        for(int i=start;i<=end;i++){
            swap(s[start],s[i]);
            solver(s,start+1,end);
            swap(s[start],s[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        solver(nums,0,nums.size()-1);
        return  v;
    }
};