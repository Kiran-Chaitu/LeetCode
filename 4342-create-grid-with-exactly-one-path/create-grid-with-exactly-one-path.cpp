class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans;
        string s = "";
        int temp = n;
        while(temp--) s+='.';
        
        ans.push_back(s);
        m--;
        while(m--){
            s="";
            temp = n;
            while(temp--){
                if(temp==0) s+='.';
                else s+='#';
            }
            ans.push_back(s);
        }
       return ans;
    }
    
};