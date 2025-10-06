class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n=nums.size();

        sort(nums.begin(),nums.end());

        vector<int>res;

        for(auto &ele:queries){
            int sum=0;
            int ans=0;
            for(int i=0;i<n;i++){
                sum+=nums[i];
                if(sum<=ele) ans++;
                else break;
            }
            res.push_back(ans);
        }
        return res;
    }
};