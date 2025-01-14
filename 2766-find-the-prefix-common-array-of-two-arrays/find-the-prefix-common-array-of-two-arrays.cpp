class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,int> mp;
        int ans=0,n=A.size();
        for(int i=0;i<n;i++){
            mp[A[i]]++;
            mp[B[i]]++;
            if(A[i]==B[i]){
                ans++;
            }
            else{
                if(mp[A[i]]==2) ans++;
                if(mp[B[i]]==2) ans++;
            }
            A[i] = ans;
        }
        return A;
    }
};