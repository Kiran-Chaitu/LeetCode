class Solution {
public:
    int minOperations(vector<string>& logs) {
        int c=0;
        for(int i=0;i<logs.size();i++){
            int n = logs[i].size();
            if(n==2){
                if(logs[i]!="./"){
                    c++;
                }
            }
            else if(n==3 and logs[i]=="../" ){
                if(c>0) c--;
            }
            else c++;
        }
        return c>0?c:0;
    }
};