class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        sort(people.begin(),people.end());
        int ans=0,n=people.size(),f=0,l=n-1;
        while(f<=l){
            if(people[f] + people[l] <= limit){
                f++;
                l--;
            }
            else l--;
            ans++;
        }
        return ans;
    }
};