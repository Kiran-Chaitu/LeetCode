class Solution {
public:
    bool isVowel(char ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U') return true;
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> ans;
        int n=queries.size();
        vector<int> v;
        long long sum=0;
        for(auto i:words){
            int sz = i.size();
            if(isVowel(i[0]) and isVowel(i[sz-1])) sum++;
            v.push_back(sum);
            cout<<sum<<" ";
        }
        cout<<endl;
        for(int i=0;i<n;i++){
            int l=queries[i][0] , r = queries[i][1] , temp=0;
            if(l==0){
                temp+=v[r];
            }
            else{
                temp+= ( v[r] - v[l-1]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};