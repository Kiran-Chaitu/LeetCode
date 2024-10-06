class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        unordered_map<int,vector<int>> gp;
        for(auto i:invocations){
            gp[i[0]].push_back(i[1]);
        }
        vector<bool> sp(n,false);
        stack<int> s;
        s.push(k);
        while(!s.empty()){
            int a = s.top();
            s.pop();
            if(!sp[a]){
                sp[a]=true;
                for(int i:gp[a]){
                    if(!sp[i]){
                        s.push(i);
                    }
                }
            }
        }
        // for(int i=0;i<sp.size();i++) cout<<sp[i]<<" ";
        // cout<<endl;
        vector<int> fn;
        bool check = false;
        for(int i=0;i<n;i++){
            if(!sp[i]){
                for(int j:gp[i]){
                    if(sp[j]){
                        check = true;
                        break;
                    }
                }
            }
            if(check) break;
        }
        //cout<<check<<endl;
        if(check){
            for(int i=0;i<n;i++){
                fn.push_back(i);
            }
        }
        else{
            for(int i=0;i<n;i++){
                if(!sp[i]){
                    fn.push_back(i);
                }
            }
        }
        return fn;
    }
};