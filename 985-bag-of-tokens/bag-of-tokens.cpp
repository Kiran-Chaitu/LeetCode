class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int i=0,j=tokens.size()-1,maxi=0,sc=0;
        while(i<=j){
            if(power >= tokens[i]){
                sc++;
                power-=tokens[i++];
                if(sc > maxi) maxi= sc;
            }
            else if(sc>=1){
                power+=tokens[j--];
                sc--;
            }
            else return maxi;
        }
        return maxi;
    }
};