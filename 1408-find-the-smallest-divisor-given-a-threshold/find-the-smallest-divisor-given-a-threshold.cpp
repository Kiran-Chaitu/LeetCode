#define ll long long
#define ld long double
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
    bool solver( vi &v,ll k,ld mid){
        ll sum=0;
        for(int i=0;i<sz(v);i++){
            ld temp = v[i];
            sum+=ceil(temp/mid);
        }
        return sum<=k;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        ll maxi=nums[0] , mini = nums[0], n = sz(nums);
        for(auto i:nums){
            if(maxi < i) maxi =i;
        }
        ll l=1,r=maxi,ans;
        while(l<=r){
            ll mid = (l+r)>>1;
            if(solver(nums,threshold,mid)){
                ans = mid;
                r = mid -1;
            }
            else l = mid +1;
        }
        return ans;
    }
};