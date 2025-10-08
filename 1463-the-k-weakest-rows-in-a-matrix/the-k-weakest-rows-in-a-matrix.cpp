class Solution {
public:
    
    int bs(vector<int>&nums){  //binary search to find index of first 0
        int left=0;
        int right=nums.size()-1;
        int ans=-1;

        while(left<=right){
            int mid=left+(right-left)/2;

            if(nums[mid]==0){
                ans=mid;
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return ans;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        unordered_map<int,int>mp; //row index, number of soldiers

        int n=mat.size();

        for(int i=0;i<n;i++){
            int idx=bs(mat[i]);

            if(idx!=-1){
                mp[i]=idx;
            }else{
                mp[i]=mat[i].size();
            }
        }

        vector<pair<int,int>>vec;

        for(auto &it:mp){
            vec.push_back({it.second,it.first}); // no of soldiers, row index

        }

        sort(vec.begin(),vec.end()); //if you store (soldiers, row_index) pairs and sort normally, C++’s std::pair comparison automatically sorts first by soldiers, then by row index.

        vector<int>ans;

        for(int i=0;i<k;i++){
            ans.push_back(vec[i].second);
        }
        return ans;

    }
};