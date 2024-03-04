class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        string tr1,tr2;
        vector<int> c1,c2;
        int c=1;
        for(int i=0;i<name.size();i++){
            //cout<<c<<" ";
            if(name[i]==name[i+1]) c++;
            else{
                tr1+=name[i];
                c1.push_back(c);
                c=1;
            }
        }
        if(c==name.size() and c!=1){
            tr1+=name[0];
            c1.push_back(c);
        } 
        c=1;
        for(int i=0;i<typed.size();i++){
            //cout<<typed[i]<<" "<<c<<" ";
            if(typed[i]==typed[i+1]) c++;
            else{ 
                tr2+=typed[i];
                c2.push_back(c);
                c=1;
            }
        }
        cout<<endl; 
        if(c==typed.size() and c!=1){
            tr1+=typed[0];
            c2.push_back(c);
        }
      /* cout<<tr1<<" "<<tr2<<endl;
        for(int i=0;i<c1.size();i++){
            cout<<c1[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<c2.size();i++){
            cout<<c2[i]<<" ";
        }*/
        if(tr1.size()!=tr2.size()) return false;
        else{
            int i=0,j=0,n=tr1.size();
            for(int i=0;i<n;i++){
                if(tr1[i]!=tr2[i]) return false;
                else if(tr1[i]==tr2[i]){
                    if(c1[i]>c2[i]) return false;                  
                }
            }
        }
        return true;
    }
};