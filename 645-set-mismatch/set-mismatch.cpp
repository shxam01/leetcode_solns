class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int>freq;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>res(2);
        for(auto &num:nums){
            freq[num]++;
            
        }
        for(int i=1;i<=n;i++){
            if(freq[i]==2){
                res[0]=i;
            }else if(freq[i]==0){
                res[1]=i;
            }
        }
        return res;
    }
};