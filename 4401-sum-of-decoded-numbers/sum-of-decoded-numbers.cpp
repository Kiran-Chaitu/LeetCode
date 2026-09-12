#define ll long long

ll mod = 1e9 + 7;

 ll modpow(ll a, ll b) {
    ll result = 1;
    a %= mod;

    while (b > 0) {
        if (b & 1) {
            result = (result * a) % mod;
        }

        a = (a * a) % mod;
        b >>= 1;
    }

    return result;
}
class Solution {
public:
    int sumDecoded(vector<long long>& nums) {
        ll ans = 0 ;
        for(ll i = 0 ; i < nums.size(); i++){
            ll w = nums[i]%10;
            ll d = nums[i]/10;
            ll nn = log10(d)  +1;
            ll ys = nn  - w;
            ll ts = modpow(10 , ys);
            ll y = d%ts , x = d /ts;
            ans = ((ans%mod)  + modpow(x,y)%mod)%mod;
        }
        return ans;
    }
};