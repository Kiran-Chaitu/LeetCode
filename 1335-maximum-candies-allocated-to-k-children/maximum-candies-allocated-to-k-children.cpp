#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define F first
#define S second

const int MOD = 1e9 + 7;
const int INF = INT_MAX;


bool solver(ll mid,vi &v,ll k){
    ll ans=0;
    for(auto i:v){
        if(ans+(i/mid) >= k) return true;
        ans+=(i/mid);
    }
    return ans >=k;
    
}

class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        sort(all(candies),greater<int>());
        ll sum=0,prev=0;
        for(auto i : candies) sum+=i;
        if(sum<k) return 0;
        ll l = 1, r = candies[0];
        while(l<=r){
            ll mid = (l+r)>>1;
            //cout<<"mid = "<<mid<<" low = "<<l<<" high = "<<r<<endl;
            if(solver(mid,candies,k)){
                prev=mid;
                l = mid +1;
            }
            else r = mid-1;
        }
        return prev;
    }
};