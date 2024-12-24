
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


class Solution {
public:
    bool solver(int mid,vi &piles,int h){
        ll sum=0,rem=0;
        for(ll i=0;i<piles.size();i++){
            sum+=(piles[i]/mid);
            if(piles[i]<mid){
                sum++;
            }
            else{
                rem=(piles[i]%mid);
                if(rem) sum++;
            }
        }
        
        //cout<<" sum = "<<sum<<" rem = "<<rem<<"\n";
        return sum<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        ll l=1,maxi=INT_MIN;
        for(int i:piles){
            if(i>maxi) maxi = i;
        }
        ll r=maxi;
        if(piles.size()==h) return maxi;
        while(l<=r){
            ll mid = (l+r)>>1;
            //cout<<"mid = "<<mid<<" low = "<<l<<" high = "<<r<<endl;
            if(solver(mid,piles,h)) r = mid -1;
            else l = mid+1;
        }
        return l;
    }
};