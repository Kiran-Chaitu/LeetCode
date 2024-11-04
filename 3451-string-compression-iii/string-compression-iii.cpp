class Solution {
public:
    string compressedString(string word) {
        string s="";
        int i=0,n=word.size(),c=1;
        while(i<n-1){
            if(word[i]==word[i+1]) c++;
            else{
                if(c>9){
                    int q = c/9;
                    int r = c%9;
                    while(q--){
                        s+='9';
                        s+=word[i];
                    }
                    if(r){ 
                        s+=to_string(r);
                        s+=word[i];
                    }
                    c=1;
                }
                else{
                    s+=to_string(c);
                    s+=word[i];
                    c=1;
                }
            }
            i++;
        }
        if(c>9){
            int q = c/9;
            int r = c%9;
            while(q--){
                s+='9';
                s+=word[i];
            }
            if(r){ 
                s+=to_string(r);
                s+=word[i];
            }
            c=1;
        }
        else{
            s+=to_string(c);
            s+=word[i];
            c=1;
        }
        return s;
    }
};