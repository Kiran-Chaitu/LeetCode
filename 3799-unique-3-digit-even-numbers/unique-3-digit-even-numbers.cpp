class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_map<int,int> mp;
        for(auto i: digits) mp[i]++;
        int c=0;
        for(int i=100;i<=998;i+=2){
            unordered_map<int,int> tmp;
            int k = i;
            while(k>0){
                int rm = k%10;
                tmp[rm]++;
                k/=10;
            }
            int ans=1;
            for(auto j:tmp){
                if(mp.find(j.first)==mp.end()  || j.second > mp[j.first]){
                    ans=0;
                    break;
                }
            }
            if(ans){
                // cout<<i<<endl;
                c++;
            }
        }
        return c;
    }
};