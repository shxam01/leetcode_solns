class Solution {
public:
    int n,m;
    typedef pair<int,pair<int,int>> p;
    
    int bfs(vector<vector<int>>&grid,vector<vector<bool>>&vis){
        priority_queue<p,vector<p>,greater<p>>pq;  // curr_time,x,y

        pq.push({grid[0][0],{0,0}});
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};

        while(!pq.empty()){
            auto current = pq.top();
            // pq.pop();
            int curr_time = current.first;
            int x = current.second.first;
            int y = current.second.second;
            pq.pop();

            vis[x][y]=true;

            if(x==n-1 && y==m-1){
                return curr_time;
            }

            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];

                if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny]){
                   int new_time=max(grid[nx][ny],curr_time);
                   pq.push({new_time,{nx,ny}});
                   vis[nx][ny]=true;
                }
            }

        }
        return -1;
    }
    int swimInWater(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();

        vector<vector<bool>>vis(n,vector<bool>(m,false));


        

        return bfs(grid,vis);
    }
};