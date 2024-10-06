class Solution {
public:
    string tobin(int n){
        string s="";
        while(n){
            int rem=n%2;
            if(rem) s+='1';
            else s+='0';
            n/=2;
        }
        reverse(s.begin(),s.end());
        return s;
    }
    int maxGoodNumber(vector<int>& nums) {
        string ans="";
        //sort(nums.begin(),nums.end());
        vector<vector<int>> perm = {
            {nums[0],nums[1],nums[2]},
            {nums[0],nums[2],nums[1]},
            {nums[1],nums[0],nums[2]},
            {nums[1],nums[2],nums[0]},
            {nums[2],nums[1],nums[0]},
            {nums[2],nums[0],nums[1]}
        };
        for(int i=0;i<6;i++){
            
            string conb="";
            for(int j=0;j<3;j++)    conb+=tobin(perm[i][j]);
            if(conb  > ans || conb.size() > ans.size()) ans = conb;
            //cout<<conb<<" "<<ans<<endl;
        }
        int sum=0;
        for(int i=0;i<ans.size();i++){
            if(ans[ans.size()-1-i]=='1'){
                sum+=pow(2,i);
                //cout<<sum<<" ";
            }
        }
        return sum;
    }
};