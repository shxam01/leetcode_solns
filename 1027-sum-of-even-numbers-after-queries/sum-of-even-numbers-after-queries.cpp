class Solution {
public:
    
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                sum+=nums[i];
            }
        }
        vector<int>res;
        
        for(auto &pr:queries){
            auto val=pr[0];
            auto index=pr[1];

            int og=nums[index];

            nums[index]+=val;

            if(og%2==0){
                if(nums[index]%2==0){
                    sum=sum-og+nums[index];
                    
                }else{
                    sum-=og;
                    // res.push_back(sum);
                }
            }else{
                if(nums[index]%2==0){
                    sum+=nums[index];
                    // res.push_back(sum);
                }else{
                    // res.push_back(sum);
                }
            }
            res.push_back(sum);
        }
        return res.size()!=0?res:vector<int>{0};
    }
};