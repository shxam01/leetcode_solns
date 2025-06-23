class Solution {
public:
    int n,m;

    bool valid(int x,int y){
        return x>=0 && x<n && y>=0 && y<m;
    }

    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};

    int bfs(vector<vector<int>>&grid,int x_src,int y_src,vector<vector<bool>>&vis){

        int ans=0;

        vis[x_src][y_src]=true;

        queue<pair<int,int>>q;

        int curr=grid[x_src][y_src];

        q.push({x_src,y_src});

        ans +=grid[x_src][y_src];

        while(!q.empty()){
            auto &pr=q.front();

            // auto curr_fish=pr.first;

            // auto coordinates=pr.first;

            auto x=pr.first;

            auto y=pr.second;

            q.pop();

            // ans=max(ans,curr_fish);


            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];

                if(valid(nx,ny) && !vis[nx][ny] && grid[nx][ny]>0){
                    vis[nx][ny]=true;
                    // int new_fish_count=curr_fish+grid[nx][ny];

                    ans +=grid[nx][ny];

                    q.push({nx,ny});
                }
            }
        }
        return ans;
    }

    int dfs(vector<vector<int>>&grid,int x_src,int y_src,vector<vector<bool>>&vis){
        vis[x_src][y_src]=true;

        int ans=grid[x_src][y_src];

        for(int i=0;i<4;i++){
            int nx=x_src+dx[i];
            int ny=y_src+dy[i];

            if(valid(nx,ny) && !vis[nx][ny] && grid[nx][ny]>0){
                ans +=dfs(grid,nx,ny,vis);
            }
        }
        return ans;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();

        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]>0){
                    // ans=max(ans,bfs(grid,i,j,vis));
                    ans=max(ans,dfs(grid,i,j,vis));
                }
            }
        }
        return ans;
    }
};