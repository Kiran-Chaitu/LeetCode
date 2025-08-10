class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans , inorder(numCourses);
        unordered_map<int, vector<int>> mp;
        for(auto i : prerequisites){
            inorder[i[0]]++;
            mp[i[1]].push_back(i[0]);
        }
        queue<int> q;
        for(int i =0 ; i < numCourses ; i++) if(!inorder[i]) q.push(i);
        while(!q.empty()){
            int nod = q.front();
            q.pop();
            for(auto i : mp[nod]){
                inorder[i]--;
                if(inorder[i] == 0) q.push(i);
            }
            ans.push_back(nod);
        }
        if(ans.size() != numCourses) return {};
        return ans;
    }
};