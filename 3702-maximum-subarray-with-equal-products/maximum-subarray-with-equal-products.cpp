
#define ll unsigned long long
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
    ll HCF(ll a,ll b){
        while(b){
            ll temp = b;
            b = a%b;
            a = temp;
        }
        return a;
    }
    ll LCM(ll a,ll b){
        return (a/HCF(a,b)) * b;
    }
    int maxLength(vector<int>& nums) {
        ll lcm,hcf , prod,n=nums.size(),ans=0;
        for(int i=0;i<n;i++){
            prod = 1,hcf = nums[i] , lcm = nums[i];
            for(int j=i;j<n;j++){
                prod*=nums[j];
                hcf = HCF(hcf , nums[j]);
                lcm = LCM(lcm,nums[j]);
                if(prod == (hcf * lcm)){
                    ll temp = j-i+1;
                    ans = max(ans , temp);
                }
            }
        }
        return ans;
    }
};