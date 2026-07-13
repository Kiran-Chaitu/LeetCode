class Solution {
public:
    void solver(vector<int> &ans,int n,int prev,int low, int high){
        if(n > high) return;
        if(n >= low and n <= high){
            ans.push_back(n);
        }
        if(prev < 9){
            int nn = (n*10) + (prev+1);
            solver(ans,nn, prev+1 , low, high);
        }
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for(int i=1;i<=9;i++){
            solver(ans,i,i, low , high);
        }
        sort(ans.begin() , ans.end());
        return ans;
    }
};