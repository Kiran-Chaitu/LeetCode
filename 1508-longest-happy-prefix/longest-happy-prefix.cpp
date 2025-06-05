#define ll long long

ll mod_mul(ll a, ll b , ll m){
    a%=m ; b%=m;
    return (a*b)%m;
}

ll mod_sub(ll a, ll b , ll m){
    a%=m ; b%=m;
    return (a-b+ m)%m;
}

ll binpow(ll a, ll b, ll m) {
    ll res = 1;
    a %= m;
    while (b > 0) {
        if (b & 1) res = mod_mul(res, a, m);
        a = mod_mul(a, a, m);
        b >>= 1;
    }
    return res;
}

// Modular inverse for prime modulus using Fermat's Little Theorem
ll mminv(ll a, ll m) {
    return binpow(a, m - 2, m);
}
struct Hashing {
    ll n;
    string s;
    ll primes;
    ll base = 31;
    vector<ll> hashPrimes = {1000000007};
    vector<vector<ll>> powers , inversePowers;
    vector<vector<ll>> hashValues;
    Hashing(string a){
        s = a;
        n = s.size();
        primes = hashPrimes.size();
        powers.resize(primes);
        inversePowers.resize(primes);
        hashValues.resize(primes);
        for(ll i=0;i<primes;i++){
            hashValues[i].resize(n);
            inversePowers[i].resize(n);
            powers[i].resize(n);
            powers[i][0] = 1;
            for(ll j = 1 ; j < n ;j++){
                powers[i][j] = (powers[i][j-1] * base) % hashPrimes[i];
                // cout<<powers[i][j]<<endl;
            }

            inversePowers[i][n-1] = mminv(powers[i][n-1] , hashPrimes[i]);
            // cout<<inversePowers[i][n-1]<<endl;
            for(ll j = n-1;j>0;j--){
                inversePowers[i][j-1] = ( inversePowers[i][j] * base ) % hashPrimes[i];
                // cout<<inversePowers[i][j-1]<<endl;
            }
            for(ll j = 0 ;j < n ;j++){
                hashValues[i][j] = (((s[j] - 'a') + 1LL) * powers[i][j])%hashPrimes[i];
                hashValues[i][j] += (( j > 0) ? hashValues[i][j-1] : 0LL)%hashPrimes[i];
            }
        }
    }
    vector<ll> subStringHash(ll l , ll r){
        vector<ll> hash(primes);
        for(ll i=0;i<primes ; i++){
            ll val1 = hashValues[i][r] ;
            ll val2 = (l > 0) ? hashValues[i][l-1] : 0LL;
            // cout<<val1 << " "<<val2<<endl;
            hash[i] = mod_mul( mod_sub(val1 , val2 , hashPrimes[i]) , inversePowers[i][l] ,hashPrimes[i]);
            // cout<<hash[i]<<endl;
        }
        // cout<<hash.size()<<endl;
        // cout<<hash[0];
        return hash;
        
    }
};

class Solution {
public:
    string longestPrefix(string s) {
        string ans = "";
        ll n = s.size() , ansl =-1 , ansr =-1;
        Hashing hash(s);
        ll l =0 , r= n -1;

        // vector<ll> temp = hash.subStringHash(0,2);
        // cout<<temp[0]<<endl;

        for(ll i =0 ; i< s.size()-1 ; i++){
            vector<ll> hashPre = hash.subStringHash(l , i);
            vector<ll> hashSuf  = hash.subStringHash(n - i -1 , r);
            if(hashPre[0] == hashSuf[0]){
                ansl = 0;
                ansr = i;
            } 
        }
        if(ansl!=-1){
            for(int i=0;i<=ansr;i++) ans+=s[i];
        }
        return ans;
    }
};