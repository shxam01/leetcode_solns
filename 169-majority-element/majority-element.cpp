class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto pr:mp){
            if(pr.second>n/2){
                return pr.first;
            }
        }
        return -1;
    }
};