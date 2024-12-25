#include<bits/stdc++.h>

using namespace std;

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
ll solver(ll mid , vi &v,ll n){
    ll ans=0;
    for(auto i:v){
        ans+=(i/mid);
        if(i%mid) ans++;
    }
    return ans> n;
    
}
class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        ll l=1,r=ln;
        for(auto i:quantities)  if(r<i) r=i;
        while(l<=r){
            ll mid=(l+r)>>1;
            if(solver(mid,quantities,n)){
                l = mid + 1;
            }
            else r = mid -1;
        }
        return l;
    }
};