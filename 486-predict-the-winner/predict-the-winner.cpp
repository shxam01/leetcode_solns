class Solution {
public:
    int n;

    int helper(vector<int>& nums, int starting_idx, int ending_idx, bool player_1_chance) {
        if (starting_idx > ending_idx) {
            return 0;
        }
        if (player_1_chance) {
            int ans = INT_MIN;
            if (starting_idx < n) ans = max(ans, helper(nums, starting_idx + 1, ending_idx, false) + nums[starting_idx]);
            if (ending_idx >= 0) ans = max(ans, helper(nums, starting_idx, ending_idx - 1, false) + nums[ending_idx]);
            return ans;
        } else {
            int ans = INT_MAX;
            if (starting_idx < n) ans = min(ans, helper(nums, starting_idx + 1, ending_idx, true) - nums[starting_idx]);
            if (ending_idx >= 0) ans = min(ans, helper(nums, starting_idx, ending_idx - 1, true) - nums[ending_idx]);
            return ans;
        }
    }

    bool predictTheWinner(vector<int>& nums) {
        n = nums.size();
        return helper(nums, 0, n - 1, true) >= 0;
    }
};
