class Solution {
public:
    vector<vector<int>>ans;
    int n;
    void helper(vector<int>&nums,int idx,vector<int>&temp){

        if(idx>=n){
           if(temp.size()>=2) ans.push_back(temp);
            return;
        }

        helper(nums,idx+1,temp); //no pick

        

        for(int i=idx;i<n;i++){
            // vector<int>temp;
            if(temp.empty() || nums[i]>=temp.back()){
                temp.push_back(nums[i]);

                helper(nums,i+1,temp);

                temp.pop_back();
            }
            

        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        n=nums.size();
        vector<int>temp;
        // temp.push_back(nums[0]);
        helper(nums,0,temp);

        set<vector<int>> st(ans.begin(), ans.end());
        ans.assign(st.begin(), st.end());
        return ans;
    }
};