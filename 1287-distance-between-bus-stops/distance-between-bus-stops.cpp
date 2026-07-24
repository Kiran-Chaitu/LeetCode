class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int rs = 0 , ls = 0 , n = distance.size();
        int i = start;
        while( i != destination){
            rs+=distance[i];
            i++;
            if(i == n) i=0;
        }
        i=start;
        while(i != destination){
            int prev = i-1;
            if(prev  < 0) prev = n-1;
            ls+=distance[prev];
            i = prev;
            
        }
        return min(rs,ls);
    }
};