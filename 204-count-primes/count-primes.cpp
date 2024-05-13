class Solution {
public:
    int seive(int n){
        vector<bool> v(n+1,true);
        v[0]=false,v[1]=false;
        for(int i=2;i<=sqrt(n);i++){
            if(v[i]){
                for(int j=i*i;j<=n;j+=i) if(v[j]) v[j]=false;
            }
        }
        int c=0;
        for(int i=2;i<n;i++) if(v[i]) c++;
        return c;
    }
    int countPrimes(int n) {
        
        return seive(n);
    }
};