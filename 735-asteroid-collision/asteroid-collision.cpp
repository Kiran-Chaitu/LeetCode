class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<int> st;
        int n = asteroids.size();
        for(int i = 0; i  < n ; i++){
            bool flag = true;
            while(!st.empty() and flag){
                if((st.top() > 0 and asteroids[i] < 0)){
                    // cout<<"HI "<<i<<endl;
                    if(abs(st.top())  < abs(asteroids[i])){
                        st.pop();
                    }
                    else if(abs(st.top()) == abs(asteroids[i])){
                        st.pop();
                        flag = false;
                    }
                    else flag = false;
                }
                else{
                    // cout<<"Bye "<<i<<endl;
                    break;
                }
            }
            if(flag) st.push(asteroids[i]);
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};