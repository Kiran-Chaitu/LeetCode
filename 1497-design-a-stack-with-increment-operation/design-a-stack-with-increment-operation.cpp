class CustomStack {
public:
    vector<int> v;
    int maxi,i=-1;
    CustomStack(int maxSize) {
        v= {};
        maxi = maxSize;
    }
    // void printl(){
    //     for(int j=0;j<v.size();j++) cout<<v[j]<<" ";
    //     cout<<endl;
    // }
    void push(int x) {
        if(i+1 < maxi){    
            v.push_back(x);
            i++;
        }
        //printl();
    }
    
    int pop() {
        if(i==-1) return -1;
        int t= v[i];
        v.pop_back();
        i--;

        //printl();
        //cout<<t<<" "<<endl;
        return t;
    }
    
    void increment(int k, int val) {
        if(k>v.size()){
            for(int j=0;j<v.size();j++){
                v[j]+=val;
            }
        }
        else{
            for(int j=0;j< k;j++){
                v[j]+=val;
            }
        }
       // printl();
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */