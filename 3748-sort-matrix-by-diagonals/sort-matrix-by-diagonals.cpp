class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        unordered_map<int,vector<int>>mp;

        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mp[i-j].push_back(grid[i][j]);
            }
        }

        for(auto &it:mp){
            if(it.first>=0){
                sort(it.second.rbegin(),it.second.rend());
            }else{
                sort(it.second.begin(),it.second.end());
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                grid[i][j]=mp[i-j].back();
                mp[i-j].pop_back();
            }
        }
        return grid;
    }

};