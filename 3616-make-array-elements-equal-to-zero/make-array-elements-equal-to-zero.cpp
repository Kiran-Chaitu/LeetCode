class Solution {
public:
    int ans=0;
    bool solver(vector<int> v,int i , int side,int n){
        while(i>=0 and i<n){
            if(v[i]==0) i+=side;
            else if(v[i]>0){
                v[i]--;
                side = -side;
                i+=side;
            }
        }
        for(int i:v) if(i!=0) return false;
        return true;
    }
    int countValidSelections(vector<int>& nums) {
        int n=nums.size();
        //vector<int> temp = {1,-1};
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                if(solver(nums,i,1,n)) ans++;
                if(solver(nums,i,-1,n)) ans++;
            }
        }
       
        return ans;
    }
};