class Solution {
public:
    int n,m;
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};

    bool valid(int x,int y){
        return x>=0 && x<n && y>=0 && y<m;
    }

    void dfs(vector<vector<char>>&grid,int x_src,int y_src,vector<vector<bool>>&vis){
        vis[x_src][y_src]=true;

        for(int i=0;i<4;i++){
            int nx=x_src+dx[i];
            int ny=y_src+dy[i];

            if(valid(nx,ny) && !vis[nx][ny] && grid[nx][ny]=='1'){
                dfs(grid,nx,ny,vis);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){

                    dfs(grid,i,j,vis);
                    ans +=1;

                }
            }
        }
        return ans;
    }
};