class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> fr(26);
        for(int i=0;i<tasks.size();i++){
            fr[tasks[i]-65]++;
        }
        sort(fr.begin(),fr.end());
        int mf=fr[25]-1;
        int id = mf*n;
        for(int i=24;i>=0;i--){
            if(fr[i]>0){
                if(mf < fr[i]) id-=mf;
                else id-=fr[i];
            }
        }
        if(id>0) return id+tasks.size();
        else return tasks.size();
    }
};