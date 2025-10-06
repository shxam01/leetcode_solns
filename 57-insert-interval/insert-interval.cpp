class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        int i = 0, n = intervals.size();

        // Add intervals before newInterval starts
        while(i < n && intervals[i][1] < newInterval[0]) {
            ans.push_back(intervals[i]);
            i++;
        }

        // Merge all intervals that overlap with newInterval
        int mergedStart = newInterval[0];
        int mergedEnd = newInterval[1];
        while(i < n && intervals[i][0] <= mergedEnd) {
            mergedStart = min(mergedStart, intervals[i][0]);
            mergedEnd = max(mergedEnd, intervals[i][1]);
            i++;
        }

        // Add the merged interval
        ans.push_back({mergedStart, mergedEnd});

        // Add remaining intervals
        while(i < n) {
            ans.push_back(intervals[i]);
            i++;
        }

        return ans;
    }
};
