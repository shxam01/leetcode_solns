class Solution {
public:
    vector<int> findOriginalArray(vector<int>& nums) {
        int n=nums.size();
        if(n%2!=0) return {};

        sort(nums.begin(),nums.end());
        unordered_map<int,int>freq;

        for(int i=0;i<n;i++){
            freq[nums[i]]++;
        }
        vector<int>res;
        for(int i=0;i<n;i++){
            if(freq[nums[i]]==0) continue;
            int doubled=nums[i]*2;
            if(freq.find(doubled)==freq.end()) return {};
            freq[nums[i]]--;
            freq[doubled]--;
            res.push_back(nums[i]);
        }
        return (res.size()==n/2)?res: vector<int>{};
    }
};