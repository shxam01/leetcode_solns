class Solution {
public:
    // int n;
    // int helper(int x, int i, int j, vector<int>& nums, int count) {
    //     // base cases
    //     if (x == 0) return count;          // found a valid way
    //     if (x < 0 || i > j) return -1;     // invalid path

    //     int left = helper(x - nums[i], i + 1, j, nums, count + 1);
    //     int right = helper(x - nums[j], i, j - 1, nums, count + 1);

    //     if (left == -1 && right == -1) return -1;  // no valid path
    //     if (left == -1) return right;
    //     if (right == -1) return left;

    //     return min(left, right);
    // }

    int n;

    int minOperations(vector<int>& nums, int x) {
        n=nums.size();
        unordered_map<int,int>mp;

        int sum=0;
        mp[0]=-1;

        for(int i=0;i<n;i++){
            sum+=nums[i];

            mp[sum]=i;
        }
        int totalsum=sum;

        int remainingSum=totalsum-x;
        if(remainingSum<0) return -1;
        if(remainingSum==0) return n;

        int longest_subarray=INT_MIN;
        sum=0;

        for(int i=0;i<n;i++){
            sum +=nums[i];
            int findsum=sum-remainingSum;

            if(mp.find(findsum)!=mp.end()){
                int idx=mp[findsum];
                longest_subarray=max(longest_subarray,i-idx);
            }
        }
        return longest_subarray==INT_MIN?-1:(n-longest_subarray);
    }
};