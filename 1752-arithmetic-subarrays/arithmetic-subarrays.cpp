class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool>ans(l.size(),false);
        for(int i=0;i<l.size();i++){
            int left=l[i];
            int right=r[i];

            vector<int> sub(nums.begin()+left, nums.begin()+right+1);

            sort(sub.begin(),sub.end());

            bool isap=true;
            int diff=sub[1]-sub[0];

            for(int j=1;j<=sub.size()-2;j++){
                if(sub[j+1]-sub[j]!=diff){
                    isap=false;
                    break;
                }
            }
            ans[i]=isap;
        }

        return ans;
    }
};