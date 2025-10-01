class Solution {
public:
    int n,m;
    int tx,ty;
    int totalcells;

    int helper(vector<vector<int>>&grid,int curr_x,int curr_y,int visited){
        int ans=0;
        if(curr_x==tx && curr_y==ty){
            return (visited==totalcells) ?1:0;
        }
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};

        int temp=grid[curr_x][curr_y];

        grid[curr_x][curr_y]=-1;
        for(int i=0;i<4;i++){
            int nx=curr_x+dx[i];
            int ny=curr_y+dy[i];

            if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]!=-1){
                ans +=helper(grid,nx,ny,visited+1);
            }
        }

        grid[curr_x][curr_y]=temp;

        return ans;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();

        int curr_x,curr_y;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=-1) totalcells++;
                if(grid[i][j]==2){
                    tx=i;
                    ty=j;
                }
                if(grid[i][j]==1){
                    curr_x=i;
                    curr_y=j;
                }
            }
        }

        

        return helper(grid,curr_x,curr_y,1);

    }
};