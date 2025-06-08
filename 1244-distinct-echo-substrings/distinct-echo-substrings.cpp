#define ll long long
ll mod_mul(ll a , ll b , ll m){
a%=m;  b%=m;
return  (a*b)%m;
}
ll mod_sub(ll a , ll b , ll m){
a%=m; b%=m;
return (a-b+m)%m;
}
ll bin_pow(ll a , ll b , ll m){
	ll res =1;
	a%=m;
	while(b>0){
		if(b&1) res= mod_mul(res,a,m);
		a = mod_mul(a,a,m);
		b>>=1;
	}
return res;
}


ll mminverse(ll a ,ll m){
	return bin_pow(a,m-2,m);
}


struct Hashing {
ll primes, n;
ll hashPrime = 1e9+7;
vector<ll> powers, inversePowers;
vector<ll> hashValues;
ll base = 31;
string s;
Hashing(string a){
n  = a.size();
s = a;
powers.resize(n) ; inversePowers.resize(n);
hashValues.resize(n);
powers[0] = 1;
for(ll i=1;i<n;i++){
powers[i] = mod_mul( powers[i-1],base , hashPrime);
// cout<<powers[i]<<" ";
}
// cout<<endl;
inversePowers[n-1] =mminverse(powers[n-1] , hashPrime) ;
for(int i = n-1;i>0;i--){
	inversePowers[i-1] = mod_mul( inversePowers[i] ,base, hashPrime); 
}
// cout<<inversePowers[0];
for(ll i=0;i<n;i++){
	hashValues[i] = (((s[i] - 'a') + 1LL) * powers[i]) % hashPrime;
	hashValues[i] =(hashValues[i] + ((i > 0) ? hashValues[i-1] : 0LL))%hashPrime;
}
}
ll subStringHash(ll l , ll r){
ll val = hashValues[r];
ll val2 = (l >0) ? hashValues[l-1] : 0LL;
return mod_mul(mod_sub(val , val2 , hashPrime) , inversePowers[l] , hashPrime);	
}
};



class Solution {
public:
    int distinctEchoSubstrings(string text) {
        unordered_map<int ,int> mp;
        Hashing hash(text);
        // cout<<hash.subStringHash(0,2);
        ll n=text.size();
        for(ll i=1;i<n;i+=2){
            for(ll j=0;j<n-i;j++){
                ll val = hash.subStringHash(j , j+(i/2));
                ll val2 = hash.subStringHash(j+(i/2)+1 , j+i);
                if(val == val2) mp[val]++;
            }
        }
        return mp.size();
    }
};