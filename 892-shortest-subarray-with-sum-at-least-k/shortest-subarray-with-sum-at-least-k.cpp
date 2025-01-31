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
    int shortestSubarray(vector<int>& nums, int k) {
        ll l=0 , r = 0 , n = nums.size() , ans = INT_MAX;
        vl pre;
        ll  totSum = 0 ;
        pre.push_back(0);
        deque<ll> dq;
        dq.push_back(0);
        while(r < n){
            totSum+=nums[r];
            pre.push_back(totSum);
            while(!dq.empty() and pre[dq.back()] > totSum){
                dq.pop_back();
            }
            while(!dq.empty() and pre[r+1] - pre[dq.front()] >= k){
                // cout<<"pre[r] = " << pre[r+1] << " pre[dq.front] = "<<pre[dq.front()]<<endl;
                // cout<<"ans = "<<ans<<" sum = "<<totSum<<endl;
                ans = min( ans ,r+1 -  dq.front());
                dq.pop_front();         
            }
            dq.push_back(r+1);
            r++;
        }
        // cout<<endl;
        // for(int i=0;i<=n;i++) cout<<pre[i]<<" ";
        if(ans == INT_MAX) return -1;
        return ans;
        
    }
};