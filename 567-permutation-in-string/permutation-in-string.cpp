class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1=s1.size(),n2 = s2.size();
        unordered_map<char,int> mp;
        for(int i=0;i<n1;i++){
            mp[s1[i]]++;
        }
        for(int i=0;i<=n2-n1;i++){
            if(mp.find(s2[i])!=mp.end()){
                unordered_map<char , int > tp = mp;
                int c=0;
                for(int j=i;j<i+n1;j++){
                    if(tp[s2[j]]>0){
                        tp[s2[j]]--;
                        c++;
                    }
                    else break;
                }
                if(c==n1) return true;
            }
        }
        return false;
    }
};