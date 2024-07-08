class Solution {
public:
    int findTheWinner(int n, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        vector<int> v(n);
        for(int i=0;i<n;i++){
            v[i] = i+1;
        }
        int i=0;
        while(n > 1){
            int j=k-1;
            while(j--){
                if(i==n-1) i=0;
                else i++;
            }
            v.erase(v.begin()+i);
           // i--;
            n--;
            if(i>n-1) i=0;
            if(n==1) break;
        }
        return v[0];
    }
};