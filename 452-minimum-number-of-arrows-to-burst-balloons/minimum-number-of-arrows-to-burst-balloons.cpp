bool compare(vector<int> a, vector<int> b){
    return a[1] < b[1];
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& v) {
        ios_base::sync_with_stdio(0);
        sort(v.begin(),v.end(),compare);
        int n=v.size();
        if(n==1) return 1;
        int c=1,i=1,k=0;
        while(i<n){
            //cout<<v[k][1]<<" "<<v[i][0]<<endl;
            if(v[k][1] < v[i][0]){
                c++;
                k=i;
                i++;
            }
            else{
                i++;
            }
        }
        //if(c==0) return n;
        return c;
    }
}; 