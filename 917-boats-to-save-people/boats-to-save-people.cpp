class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int ans=0,n=people.size(),f=0,l=n-1;
        while(f<=l){
            if(people[f] + people[l] <= limit){
                f++;
                l--;
                ans++;
            }
            else{
                ans++;
                l--;
            }
        }
        return ans;
    }
};