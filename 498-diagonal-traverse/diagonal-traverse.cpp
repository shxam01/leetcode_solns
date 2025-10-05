class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        unordered_map<int,vector<int>>mp;

        int n=mat.size();
        int m=mat[0].size();

        int k=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mp[i+j].push_back(mat[i][j]);   // 1 , 2 4 , 3 5 7, 6 8, 9
            }
        }
        vector<int>ans;
        
        for (int sum = 0; sum <= n + m - 2; sum++) {
            auto &vec = mp[sum];
            if (sum % 2 == 0) {
                reverse(vec.begin(), vec.end());
            }
            ans.insert(ans.end(), vec.begin(), vec.end());
        }
        return ans;
    }
};