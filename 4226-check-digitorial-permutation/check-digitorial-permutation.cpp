class Solution {
public:
    bool isDigitorialPermutation(int n) {
        vector<int> ft = {1,1,2,6,24,120,720 ,5040, 40320, 362880 };        
        unordered_map<int,int> mp ,fact;
        for(int i = 0; i <=9;i++){
            fact[i] = ft[i];
        }
        int temp = n , ds =0 ;
        while(temp > 0){
            mp[temp%10]++;
            ds+= fact[temp%10];
            temp /= 10;
        }
        while(ds > 0){
            mp[ds%10]--;
            ds/=10;
        }
        for(auto i : mp){
            if(i.second !=0) return false;
        }
        return true;
    }
};