class Solution {
public:
    int findComplement(int num) {
        int ans=0;
        vector<int> v;
        while(num){
            if(num&1)   v.push_back(0);
            else v.push_back(1);
            num>>=1;
        }
        for(int i=0;i<v.size();i++){
            //cout<<v[i]<<" * "<<pow(2,i)<<" ";
            ans += (v[i]*pow(2,i));
            //cout<<ans<<endl;
        }
        return ans;
    }
};