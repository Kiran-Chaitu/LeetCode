class Solution {
public:
    int solver(int n){
        vector<int> v;
        while(n){
            v.push_back(n%10);
            n/=10;
        }
        if(v.size() < 3) return 0;
        n = v.size();
        int ans = 0;
        for(int i=1; i < n-1;i++){
            if(v[i]  > v[i+1] and v[i] > v[i-1]) ans++;
            else if(v[i] < v[i+1] and v[i] < v[i-1]) ans++;
        }
        return ans;
    }
    int totalWaviness(int num1, int num2) {
        int ans=0;
        for(int i = num1;i<=num2;i++){
            ans+=solver(i);
        }
        return ans;
    }
};