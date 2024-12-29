class Solution {
public:
    string answerString(string word, int numFriends) {
        int k = (word.size() - numFriends)+1;
        int n = word.size();
        if(numFriends==1) return word;
        string ans="";
       // cout<<k<<" n="<<n<<endl;
        for(int i=0;i<=n;i++){
            string s="";
            for(int j=i;j<min(n,k);j++){
                s += word[j];
            //    cout<<s<<" ";
            }
            if(ans < s) ans=s;
            k++;
            // cout<<endl;
        }
        return ans;
    } 
};