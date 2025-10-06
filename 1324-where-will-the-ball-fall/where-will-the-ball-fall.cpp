class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<int>ans(m,-1);

        for(int ball=0;ball<m;ball++){
            int row=0;
            int col=ball;

            while(row<n && col<m){
                if(grid[row][col]==1){
                   if( col==m-1 || grid[row][col+1]==-1){
                    col=-1;
                    break;
                   }else{
                    row++;
                    col++;
                   }
                }else{
                    if(col==0 || grid[row][col-1]==1){
                        col=-1;
                        break;
                    }else{
                        row++;
                        col--;
                    }
                }
                
            }
            if(col!=-1){
                ans[ball]=col;
            }
        }
        return ans;
    }
};