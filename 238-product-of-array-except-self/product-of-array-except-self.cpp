class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size=nums.size();
        vector<int> pr(size,1),sf(size,1),ans;
        int p=1,j,i;
        for(i=0;i<nums.size();i++){
            p*=nums[i];
            pr[i]=p;
        }
        p=1;
       for(i=nums.size()-1;i>=0;i--){
            p*=nums[i];
            sf[i]=p;
        }
        //reverse(sf.begin(),sf.end());
        i=-1;
        j=1;
        int n=pr.size()-1;
        //cout<<i<<" "<<n<<" "<<j<<endl;
        while(i < n){
            //cout<<i<<" "<<j<<" ";
            if(i==-1){
               ans.push_back(1*sf[j]);
            } 
            else if(j==sf.size())   ans.push_back(1*pr[i]);
            else{
                ans.push_back(pr[i]*sf[j]);
            }
            j++;
            i++;
        }
        return ans;
    }
};