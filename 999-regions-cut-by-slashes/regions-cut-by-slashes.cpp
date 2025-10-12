class Solution {
public:
    int n,m;

    void dfs(vector<vector<int>>&mat,int x,int y,vector<vector<bool>>&vis){
        int dx[4]={0,0,-1,1};
        int dy[4]={-1,1,0,0};
        vis[x][y]=true;
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];

            if(nx>=0 && nx<n*3 && ny>=0 && ny<m*3 && mat[nx][ny]==0 && !vis[nx][ny]){
                // vis[nx][ny]=true;
                dfs(mat,nx,ny,vis);
            }
        }
    }
    int regionsBySlashes(vector<string>& grid) {
        n=grid.size();
        m=grid[0].size();

        int rows=n*3;
        int cols=m*3;

        vector<vector<int>>mat(rows,vector<int>(cols,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='/'){
                    mat[i*3][j*3+2]=1;
                    mat[i*3+1][j*3+1]=1;
                    mat[i*3+2][j*3]=1;
                }else if(grid[i][j]=='\\'){
                    mat[i*3][j*3]=1;
                    mat[i*3+1][j*3+1]=1;
                    mat[i*3+2][j*3+2]=1;
                }
            }
        }

        vector<vector<bool>>vis(rows,vector<bool>(cols,false));
        int cnt=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(!vis[i][j] && mat[i][j]==0){
                    dfs(mat,i,j,vis);
                    cnt++;
                }
            }
        }
        return cnt;


    }
};