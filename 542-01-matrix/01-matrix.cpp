class Solution {
public:
    int n,m;

    vector<vector<int>> bfs(vector<vector<int>>&mat){
        queue<pair<int,int>>q;

        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }

        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};

        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();

            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];

                if(nx>=0 && nx<n && ny>=0 && ny<m && dist[nx][ny]>dist[x][y]+1){
                    dist[nx][ny]=dist[x][y]+1;
                    q.push({nx,ny});
                }
            }
        }
        return dist;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        n=mat.size();
        m=mat[0].size();

        return bfs(mat);
    }
};