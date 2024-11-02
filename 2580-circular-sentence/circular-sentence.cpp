class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n=sentence.size(),i=0;
        if(sentence[0]!=sentence[n-1]) return false;
        while(i<n-1){
            int j=i;
            while(j<n-1 and sentence[j]!=' ') j++;
            if(j<n-1 and sentence[j-1]!=sentence[j+1]) return false;
            i=j+1;
        }
        return true;

    }
};