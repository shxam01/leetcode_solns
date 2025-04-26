#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Single‐pass sliding window:
    // lastInvalid — the last index where nums[idx] was outside [minK…maxK]
    // lastMin     — most recent index where nums[idx]==minK
    // lastMax     — most recent index where nums[idx]==maxK
    // At each j we add max(0, min(lastMin, lastMax) - lastInvalid)
    // which is the number of new valid subarrays ending at j.
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        int lastInvalid = -1, lastMin = -1, lastMax = -1;
        long long ans = 0;
        for (int j = 0; j < n; ++j) {
            int x = nums[j];
            if (x < minK || x > maxK) {
                // window must restart after j
                lastInvalid = j;
            }
            if (x == minK) lastMin = j;
            if (x == maxK) lastMax = j;
            // any subarray ending at j that includes both a minK and maxK
            // must start at or before min(lastMin,lastMax), and after lastInvalid
            int validStart = min(lastMin, lastMax);
            if (validStart > lastInvalid) {
                ans += (validStart - lastInvalid);
            }
        }
        return ans;
    }
};