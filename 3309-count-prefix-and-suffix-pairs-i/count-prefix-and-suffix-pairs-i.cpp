class Solution {
public:
    bool isPrefixAndSuffix(string str1, string str2) {
        int n=str1.size(),m=str2.size()-1;
        for(int i=0;i<n;i++){
            if(str1[i]!=str2[i]) return false;
        }
        for(int i=n-1;i>=0;i--){
            if(str1[i]!=str2[m]) return false;
            m--;
        }
        return true;
        
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        int n = words.size();  
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) { 
                if (isPrefixAndSuffix(words[i], words[j])) {
                    count++;
                }
            }
        }

        return count;
    }
};