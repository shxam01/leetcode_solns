class Solution {
public:
    int n,m;
    void dfs(vector<vector<int>>&grid,vector<vector<bool>>&vis,int x,int y){
        vis[x][y]=true;
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==1 && !vis[nx][ny]){
                dfs(grid,vis,nx,ny);
            }
        }
    }
    int check_no_of_islands(vector<vector<int>>&grid){
        int islands=0;
        n=grid.size();
        m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    dfs(grid,vis,i,j);
                    islands++;
                }
            }
        }
        return islands;
    }
    int minDays(vector<vector<int>>& grid) {
        int islands=check_no_of_islands(grid);
        if(islands>1 || islands==0) return 0;
       
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    grid[i][j]=0;
                    int new_islands=check_no_of_islands(grid);
                    if(new_islands!=1) return 1;
                    grid[i][j]=1;
                }
            }
        }
        return 2;
        
    }
};
