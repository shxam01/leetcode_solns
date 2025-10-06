class Solution {
public:
    int n,m;
    bool valid(int x,int y){
        return x>=0 && x<n && y>=0 && y<m;
    }
    bool dfs(vector<vector<int>>&grid,int x,int y,vector<vector<bool>>&vis){

        if(!valid(x,y)) return false;

        if(grid[x][y]==1 || vis[x][y]) return true;

        vis[x][y]=true;

        bool left=dfs(grid,x,y-1,vis);
        bool right=dfs(grid,x,y+1,vis);
        bool up=dfs(grid,x-1,y,vis);
        bool down=dfs(grid,x+1,y,vis); 

        

        return left && right && up && down;
    }
    int closedIsland(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();

        vector<vector<bool>>vis(n,vector<bool>(m,false));

        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0 && !vis[i][j]){
                    if(dfs(grid,i,j,vis)) ans++;
                }
            }
        }
        return ans;
    }
};