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
const ll lx = LLONG_MAX;
const ll ln = LLONG_MIN; 

ll solver(ll mid,vi &ranks,ll cars){
   ll sum=0;
   for(ll i=0;i<sz(ranks);i++){
        if(sum + sqrt(mid/ranks[i]) >= cars) return true;
        sum+=sqrt(mid/ranks[i]);
   }
   return sum>=cars;
    
}


class Solution {
public:
    long long repairCars(vector<int>& ranks, ll cars) {
        sort(all(ranks));
        ll mini=ranks[0],maxi = ranks[sz(ranks)-1];
        maxi = maxi * (cars*cars);
        ll l=mini,r=maxi;
        while(l<=r){
            ll mid = (l+r)>>1;
            if(solver(mid,ranks,cars)){
                r = mid-1;
            }
            else l = mid +1;
        }
        return l;
    }
};