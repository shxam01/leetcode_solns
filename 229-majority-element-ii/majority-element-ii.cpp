class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int a=nums.size()/3;
        unordered_map<int,int>freq;
        for(auto ele:nums){
            freq[ele]++;
        }
        vector<int>ans;
        for(auto pr:freq){
            if(pr.second>a){
                ans.push_back(pr.first);
            }
        }
        return ans;
    }
};