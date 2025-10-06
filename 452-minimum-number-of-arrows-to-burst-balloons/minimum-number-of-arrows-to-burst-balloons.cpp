class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty()) return 0;
        sort(points.begin(), points.end(), [](const auto& a, const auto& b){
    return a[1] < b[1];
});


        int curr_ending_point=points[0][1];

        int n=points.size();

        int i=1;

        int ans=1;

        while(i<n){
            while(i<n && points[i][0]<=curr_ending_point){
                i++;
            }
            if(i<n && points[i][0]>curr_ending_point){
                curr_ending_point=points[i][1];
                ans++;
                i++;
            }
        }
        return ans;

    }
};