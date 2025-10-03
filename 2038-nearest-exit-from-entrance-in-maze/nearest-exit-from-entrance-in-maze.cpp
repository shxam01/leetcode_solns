class Solution {
public:

    typedef pair<int,pair<int,int>> p;

    int n,m;

    bool boundary(int x,int y){
        return x==n-1 || y==m-1 || x==0 || y==0;
    }

    bool valid(int x,int y){
        return x>=0 && x<n && y>=0 && y<m;
    }

    

    int bfs(vector<vector<char>>&maze,int sx,int sy,vector<vector<bool>>&vis){
        priority_queue<p,vector<p>,greater<p>>pq;

        pq.push({0,{sx,sy}});

        vis[sx][sy]=true;

        

        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};

        while(!pq.empty()){

            auto [curr_dist,coordinates]=pq.top();

            auto [x,y]=coordinates;

            pq.pop();

            if(boundary(x,y) && !(x==sx && y==sy)) return curr_dist;

            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];

                if(valid(nx,ny) && maze[nx][ny]=='.' && !vis[nx][ny]){
                    int new_dist=curr_dist+1;
                    pq.push({new_dist,{nx,ny}});
                    vis[nx][ny]=true;
                }
            }

        }
        return -1;
    }
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
         n=maze.size();
         m=maze[0].size();
        //  vector<vector<int>>mazee(n,vector<int>(m));
        //  for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         mazee[i][j]=maze[i][j]-'a';
        //     }
        //  }

        vector<vector<bool>>vis(n,vector<bool>(m,false));

         return bfs(maze,entrance[0],entrance[1],vis);

    }
};