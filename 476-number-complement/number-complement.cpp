class Solution {
public:
    int findComplement(int num) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        int ans=0,i=0;
        while(num){
            cout<<(num&1)<<" "<<(2<<i)<<" "<<ans<<endl;
            if(!(num&1)) (i!=0) ? ans+=(2<<(i-1)):ans+=1;
            num>>=1;
            i++;
        }
        return ans;
    }
};