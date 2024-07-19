
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
       vector<int> rm,ch,ans;
       int mini=100009;
       int maxi=0;
       for(int i=0;i<matrix.size();i++){
           mini=INT_MAX;
           for(int j=0;j<matrix[0].size();j++){
               if(matrix[i][j]<mini) mini=matrix[i][j];
           }
           rm.push_back(mini);
       }
       for(int i=0;i<matrix[0].size();i++){
           maxi=0;
           for(int j=0;j<matrix.size();j++){
               if(maxi<matrix[j][i]) maxi=matrix[j][i];
           }
           ch.push_back(maxi);
       } 
       int x=rm.size(),y=ch.size();
        unordered_map<int,int> mp;
       for(int i=0;i<rm.size();i++){
           mp[rm[i]]=1;
       }
       for(int i=0;i<y;i++){
            if(mp.find(ch[i])!=mp.end()){
                ans.push_back(ch[i]);
            }
       }
       return ans;
    }
};