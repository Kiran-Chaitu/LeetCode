class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        int n = nums2.size();
        vector<int> ans(n,-1);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() and nums2[i] >= st.top()) st.pop();
            if(!st.empty()) ans[i]=st.top();
            st.push(nums2[i]);
        }
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++) mp[nums2[i]]=ans[i];
        vector<int> v;
        for(int i=0;i<nums1.size();i++){
            v.push_back(mp[nums1[i]]);
        }
        return v;
    }
};