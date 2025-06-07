class Solution {
public:
    int n;
    bool isPossible(int x,int y){
        return x>=0 && x<n && y>=0 && y<n; 
    }

    int bfs(vector<vector<int>>&grid,int x_src,int y_src,vector<vector<int>>&vis){

        if(grid[x_src][y_src]==1 || grid[n-1][n-1]==1){
            return -1;
        }
        vis[x_src][y_src]=1;

        queue<pair<int,pair<int,int>>>q;
        q.push({1,{x_src,y_src}});
        int ans=INT_MAX;

        vector<vector<int>>drcns={{0,1},{0,-1},{1,0},{-1,0},{-1,-1},{1,1},{1,-1},{-1,1}};;
        // drcns= {{0,1},{0,-1},{1,0},{-1,0},{-1,-1},{1,1},{1,-1},{-1,1}};
        
        while(!q.empty()){
            auto dist=q.front().first;

            auto x=q.front().second.first;
            auto y=q.front().second.second;

            q.pop();
            if(x==n-1 && y==n-1){
                return dist;
            }
            for(int i=0;i<8;i++){
                auto dx=drcns[i][0];
                auto dy=drcns[i][1];

                auto nx=x+dx;
                auto ny=y+dy;

                if(isPossible(nx,ny) && grid[nx][ny]==0 && vis[nx][ny]==0){
                    vis[nx][ny]=1;
                    q.push({dist+1,{nx,ny}});
                }
            }
        }
        return -1;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        n=grid.size();
        vector<vector<int>>vis(n,vector<int>(n,0));
        int ans=bfs(grid,0,0,vis);
        return ans;
    }
};