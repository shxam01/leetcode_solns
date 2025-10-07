class Solution {
public:
    int n,m;

    bool valid(int x,int y){
        return x>=0 && x<n && y>=0 && y<m;
    }

    void dfs(vector<vector<int>>&grid,int x,int y,vector<vector<bool>>&vis){
        if(!valid(x,y) || vis[x][y] || grid[x][y]!=1) return;
        vis[x][y]=true;
        grid[x][y]=2;
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        for(int i=0;i<4;i++) dfs(grid,x+dx[i],y+dy[i],vis);
    }

    int bfs(vector<vector<int>>&grid,vector<vector<bool>>&vis,int x,int y){
        queue<pair<pair<int,int>,int>>q;
        q.push({{x,y},0});
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};

        while(!q.empty()){
            auto [p,dist]=q.front();q.pop();
            auto [i,j]=p;
            for(int k=0;k<4;k++){
                int nx=i+dx[k],ny=j+dy[k];
                if(valid(nx,ny) && !vis[nx][ny]){
                    if(grid[nx][ny]==1) return dist;
                    vis[nx][ny]=true;
                    q.push({{nx,ny},dist+1});
                }
            }
        }
        return INT_MAX;
    }

    int shortestBridge(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        bool found=false;
        for(int i=0;i<n && !found;i++){
            for(int j=0;j<m && !found;j++){
                if(grid[i][j]==1){
                    dfs(grid,i,j,vis);
                    found=true;
                }
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    vector<vector<bool>>tmp=vis;
                    ans=min(ans,bfs(grid,tmp,i,j));
                }
            }
        }
        return ans;
    }
};
