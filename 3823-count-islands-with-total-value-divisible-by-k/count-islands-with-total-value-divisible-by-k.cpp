class Solution {
public:
    int m,n;
    typedef long long ll;
    
    ll bfs(vector<vector<int>>&grid,int x_src,int y_src,vector<vector<bool>>&vis){
        vis[x_src][y_src]=true;
        queue<pair<int,int>>q;
        q.push({x_src,y_src});

        // components.push_back(grid[x_src][y_src]);
        ll curr_sum=grid[x_src][y_src];

        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,1,-1};

        while(!q.empty()){
            auto pr=q.front();
            auto x=pr.first;
            auto y=pr.second;
            q.pop();

            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];

                if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]!=0 && !vis[nx][ny]){
                    vis[nx][ny]=true;
                    q.push({nx,ny});
                    // components.push_back(grid[nx][ny]);
                    curr_sum +=grid[nx][ny];
                }
            }
        }
        return curr_sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        n=grid.size();
        m=grid[0].size();

        vector<vector<bool>>vis(n,vector<bool>(m,false));

        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0 && !vis[i][j]){
                    // vector<int>components;
                    ll sum=bfs(grid,i,j,vis);
                    // ll sum=accumulate(components.begin(),components.end(),0);
                    if(sum%k==0) ans++;
                }
            }
        }
        return ans;
    }
};