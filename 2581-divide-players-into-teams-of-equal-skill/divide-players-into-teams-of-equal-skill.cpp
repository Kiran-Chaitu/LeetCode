class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long ans=0,c=0;
        int i=0,n=skill.size(),j=n-1;
        unordered_map<long long,int > mp;
        sort(skill.begin(),skill.end());
        while(i < (n/2)){
            long long sum =skill[i++] + skill[j--];
            mp[sum]++; 
        }
        if(mp.size()!=1) return -1;
        i=0,j=n-1;
        while(i<(n/2)){
            long long pro = skill[i++] * skill[j--];
            ans+=pro;
        }
        return ans;
    }
};