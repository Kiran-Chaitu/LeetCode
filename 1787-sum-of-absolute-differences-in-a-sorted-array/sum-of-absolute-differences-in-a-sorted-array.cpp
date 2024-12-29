
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
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        ll sum=0,n=nums.size();
        vector<ll> pr(n),sf(n);
        for(int i=0;i<n;i++){
            pr[i] = (sum);
            sum+=nums[i];
        }
        sum=0;
        for(int i=n-1;i>=0;i--){
            sf[i] = (sum);
            sum+=nums[i];
            
        }
        vector<int> ans(n);
        for(int i=0;i<nums.size();i++){
            //cout<<"prefix = "<<pr[i]<<" sufiix = "<<sf[i]<<endl;
            ans[i]=((nums[i]*(i)) -pr[i]) + (sf[i] - (nums[i]* (n-i-1)));
        }
        return ans;
    }
};