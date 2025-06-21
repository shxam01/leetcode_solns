class Solution {
public:
    int n,m;
    typedef pair<int,pair<int,int>> p;
    bool valid(int x,int y){
        return x>=0 && x<n && y>=0 && y<m;
    }
    int solve(vector<vector<int>>&grid,int x_src,int y_src){
        priority_queue<p,vector<p>,greater<p>>pq;
        pq.push({0,{x_src,y_src}});
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        while(!pq.empty()){
            auto pr=pq.top();
            auto curr_time=pr.first;
            auto coordinates=pr.second;
            auto x=coordinates.first;
            auto y=coordinates.second;
            if(x==n-1 && y==m-1) return curr_time;
            if (curr_time > dist[x][y]) continue;
            pq.pop();
            for(int i=0;i<4;i++){
                int x_new=x+dx[i];
                int y_new=y+dy[i];
                if(valid(x_new,y_new)){

                    int next_time=curr_time+1;
                    if(grid[x_new][y_new]>next_time){
                        int wait_time=grid[x_new][y_new]-next_time;
                        if(wait_time%2==0){
                            next_time=grid[x_new][y_new];
                        }else{
                            next_time=grid[x_new][y_new]+1;
                        }
                    }
                    if(next_time<dist[x_new][y_new]){
                        // next_time=curr_time+1;
                        dist[x_new][y_new]=next_time;
                        pq.push({next_time,{x_new,y_new}});
                    }
                }
            }
        }
        return -1;
    }
    int minimumTime(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        if (grid[0][1] > 1 && grid[1][0] > 1) {
          return -1;
        }
        return solve(grid,0,0);
    }
};