class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        sort(seats.begin(),seats.end());
        sort(students.begin(),students.end());
        int c=0;
        for(int i=0;i<seats.size();i++) c+=abs(seats[i] - students[i]);
        return c;
    }
};