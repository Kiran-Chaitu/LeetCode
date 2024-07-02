
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        unordered_map <int,int> m;
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            m[nums1[i]]++;
        }
        for(int i=0;i<nums2.size();i++){
            if(m[nums2[i]]>0){
                ans.push_back(nums2[i]);
                m[nums2[i]]--;
            } 
        }
        return ans;
    }
};