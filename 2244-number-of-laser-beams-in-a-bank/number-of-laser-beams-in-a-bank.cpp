class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> v;
        int c=0;
        for(auto i:bank ){
            c=0;
            for(int j=0;j<i.size();j++){
                if(i[j]=='1') c++;
            }
            if(c!=0) v.push_back(c);
        }
        int sum=0;
        if(v.size()==1 or v.size()==0) return 0;
        else{
            for(int i=0;i<v.size()-1;i++){

                sum+=v[i]*v[i+1];
                //cout<<v[i]<<" "<<sum;
            }
            
        }   
        return sum;     
    }
};