class Solution {
public:
    int maxScore(string s) {
        int n=s.size();
        vector<int> prefix(n),suffix(n);
        int sum=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0') sum++;
            prefix[i] = sum;
        }
        if(sum==n) return n-1;
        //cout<<sum<<" "<<n<<endl;
        sum=0;
        for(int i=n-1;i>=0;i--){
            suffix[i]=sum;
            if(s[i]=='1') sum++;
        }
        //cout<<sum<<n<<endl;
        if(sum==n) return n-1;
        sum=0;
        for(int i=0;i<n-1;i++){
            //cout<<prefix[i]<<" "<<suffix[i]<<endl;
            sum = max(sum, prefix[i]  + suffix[i]);
        }
        return sum;
    }
};