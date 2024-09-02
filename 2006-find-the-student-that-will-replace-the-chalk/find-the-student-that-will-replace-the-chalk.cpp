class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        long long int sum=0;
        for(int i=0;i<chalk.size();i++) sum+=chalk[i];
        long long int rem = k%sum;
        if(rem==0) return 0;
        for(int i=0;i<chalk.size();i++){
            if(rem<chalk[i]) return i;
            rem-=chalk[i];
        }
        return 0;
    }
};