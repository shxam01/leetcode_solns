class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,vector<int>>num_pos; // numbers and their positions
        for(int i=0;i<nums.size();i++){
            // if(num_pos.find(nums[i]))
            num_pos[nums[i]].push_back(i);
        }
        for(auto &it:num_pos){
            auto vec=it.second;
            if(vec.size()<2) continue;
            sort(vec.begin(),vec.end());
            for (int i = 1; i < vec.size(); i++) {
                if (vec[i] - vec[i - 1] <= k) {
                    return true;
                }
            }
        }
        return false;
    }
};