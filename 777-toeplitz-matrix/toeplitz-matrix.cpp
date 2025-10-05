class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        unordered_map<int,vector<int>>mp;

        int n=matrix.size();
        int m=matrix[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mp[i-j].push_back(matrix[i][j]);
            }
        }

        for(auto &it:mp){
            auto vec=it.second;
            for(int i=1;i<vec.size();i++){
                if(vec[i]!=vec[0]) return false;
            }
        }
        return true;
    }
};