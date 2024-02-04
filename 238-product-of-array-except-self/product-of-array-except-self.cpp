class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pr,sf,ans;
        int p=1,j,i;
        for(i=0;i<nums.size();i++){
            p*=nums[i];
            pr.push_back(p);
        }
        p=1;
       for(i=nums.size()-1;i>=0;i--){
            p*=nums[i];
            sf.push_back(p);
        }
        reverse(sf.begin(),sf.end());
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