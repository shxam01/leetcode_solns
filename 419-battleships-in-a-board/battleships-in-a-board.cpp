class Solution {
public:
    int n,m;
    bool valid(int x,int y){
        return x>=0 && x<n && y>=0 && y<m;
    }
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};

    void dfs(vector<vector<char>>&board,int x,int y,vector<vector<bool>>&vis){
        vis[x][y]=true;

        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];

            if(valid(nx,ny) && !vis[nx][ny] && board[nx][ny]=='X'){
                dfs(board,nx,ny,vis);
            }
        }
    }
    int countBattleships(vector<vector<char>>& board) {
        n=board.size();
        m=board[0].size();

        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]=='X'){
                    dfs(board,i,j,vis);
                    ans++;
                }
            }
        }
        return ans;
    }
};