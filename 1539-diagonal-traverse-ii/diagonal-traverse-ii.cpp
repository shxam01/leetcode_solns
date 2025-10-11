class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int n=nums.size();
        map<int,vector<int>>mp;

        for(int i=0;i<n;i++){
            for(int j=0;j<nums[i].size();j++){
                mp[i+j].push_back(nums[i][j]);
            }
        }

        vector<int>ans;

        for(auto pr:mp){
            auto vec=pr.second;
            reverse(vec.begin(),vec.end());
            ans.insert(ans.end(),vec.begin(),vec.end());
        }

        // reverse(ans.begin(),ans.end()); 

        return ans;
    }
};