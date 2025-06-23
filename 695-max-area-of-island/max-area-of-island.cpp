class Solution {
public:
    int n,m;
    bool valid(int x,int y){
        return x>=0 && x<n && y>=0 && y<m;
    }
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};

    int bfs(vector<vector<int>>&grid,int x_src,int y_src,vector<vector<bool>>&vis){
        int count=1;
        queue<pair<int,int>>q;

        q.push({x_src,y_src});

        vis[x_src][y_src]=true;

        while(!q.empty()){
            auto [x,y]=q.front();

            q.pop();

            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];

                if(valid(nx,ny) && !vis[nx][ny] && grid[nx][ny]==1){
                    count++;
                    vis[nx][ny]=true;
                    q.push({nx,ny});
                }
            }

        }
        return count;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        n=grid.size();
        m=grid[0].size();

        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    ans=max(ans,bfs(grid,i,j,vis));
                }
            }
        }
        return ans;
        
    }
};