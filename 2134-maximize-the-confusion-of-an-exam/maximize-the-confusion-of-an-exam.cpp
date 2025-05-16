class Solution {
public:
    int solver(string s , int k , char ch){
        int c=0,i=0,j=0,n=s.size(),maxi=INT_MIN;
        queue<int> q;
        while(j<n){
            if(s[j]==ch){
                c++;
                q.push(j);
            }
            while(c > k){
                i = q.front() + 1;
                q.pop();
                c--;
            }

            maxi=max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(solver(answerKey , k , 'T') , solver(answerKey , k , 'F'));
    }
};