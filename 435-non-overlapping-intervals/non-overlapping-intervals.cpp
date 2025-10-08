class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());

        int i=0;
        int j=1;
        int n=intervals.size();

        int cnt=0;

        while(j<n){
            if(i==j) j++;
            int cs=intervals[i][0];
            int ce=intervals[i][1];
            int ns=intervals[j][0];
            int ne=intervals[j][1];
            if(ce<=ns){
                i=j;
                j++;
            }else if(ce<=ne){
               j++;
               cnt++;
            }else if(ce>ne){
                i=j;
                j++;
                cnt++;
            }
        }

        return cnt;
    }
};