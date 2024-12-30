
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


class Solution {
public:
    bool solver(vi &v,ll mid,ll k,ll m){
        ll c=0,ans=0;
        for(int i=0;i<v.size();i++){
            if(v[i] <= mid){
                c++;
                if(c>=k){
                    ans++;
                    c=0;
                }
            }
            else c=0;
            if(ans>=m) return true;
        }
        return ans >=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        ll n = bloomDay.size();
        ll temp = (ll)m*(ll)k;
        if(n < (temp)) return -1;
        ll maxi=bloomDay[0],mini=bloomDay[0];
        for(int i=1;i<n;i++){ 
            if(maxi < bloomDay[i])   maxi = bloomDay[i];
            if(mini > bloomDay[i])  mini = bloomDay[i];
        }
        ll l=mini,r=maxi;
        while(l<=r){
            ll mid = (l+r)>>1;
            if(solver(bloomDay,mid,k,m)) r=mid-1;
            else l = mid +1;
        }
        return l;
    }
};