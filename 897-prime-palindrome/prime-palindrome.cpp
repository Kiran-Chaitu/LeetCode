vector<bool> ans;
class Solution {
public:
    bool ispal(string s){
        int r=s.size()-1,l=0;
        while(l<r){
            if(s[l++]!=s[r--]) return false;
        }
        return true;

    }
    void sieve(int n){
        vector<bool> v(n+1,true);
        v[0]=false,v[1]=false;
        for(int i=2;i<=sqrt(n);i++){
            if(v[i]){
                for(int j=i*i;j<=n;j+=i){
                    if(v[j]) v[j]=false;
                }
            }
        }
        ans = v;
    }
    int primePalindrome(int n) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        int b=(9989900);
        if(n >= b) return 100030001;
        if(ans.size() ==0) sieve(b);
        for(int i=n;i<=b;i++){
            if(ans[i]){
                if(ispal(to_string(i))) return i;
            }
        }
        return 2;
    }
};