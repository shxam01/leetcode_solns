class Solution {
public:
    int n,m;
    bool canmove(int x,int y){
        return x>=0 && x<n && y>=0 && y<m;
    }
    bool bfs(vector<vector<int>>&grid,int x,int y,vector<vector<bool>>&vis){
        vis[x][y]=true;
        queue<pair<int,int>>q;
        q.push({x,y});
        vector<vector<pair<int,int>>>dirs={
            {},
            {{0,-1},{0,1}},
            {{-1,0},{1,0}},
            {{0,-1},{1,0}},
            {{0,1},{1,0}},
            {{0,-1},{-1,0}},
            {{0,1},{-1,0}}
        };
        while(!q.empty()){
            auto [cx,cy]=q.front();q.pop();
            if(cx==n-1&&cy==m-1)return true;
            for(auto [dx,dy]:dirs[grid[cx][cy]]){
                int nx=cx+dx,ny=cy+dy;
                if(canmove(nx,ny)&&!vis[nx][ny]){
                    for(auto [rdx,rdy]:dirs[grid[nx][ny]]){
                        if(nx+rdx==cx&&ny+rdy==cy){
                            vis[nx][ny]=true;
                            q.push({nx,ny});
                        }
                    }
                }
            }
        }
        return false;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        return bfs(grid,0,0,vis);
    }
};
