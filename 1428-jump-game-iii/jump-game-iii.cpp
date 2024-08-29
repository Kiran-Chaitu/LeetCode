class Solution {
public:
    bool ans=false;
    void solver(vector<int> &arr,int ind,vector<int> &check){
        if(ind<0 || ind>=arr.size()) return;
        if(arr[ind]==0){
            ans=true;
            return;
        }
        if(check[ind]) return;
        check[ind]=1;
        solver(arr,ind + arr[ind],check);
        solver(arr,ind - arr[ind],check);
    }
    bool canReach(vector<int>& arr, int start) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        vector<int> check (arr.size());
        solver(arr,start,check);
        return ans;
    }
};