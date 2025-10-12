class Solution {
public:
    int n,m;
    bool helper(vector<vector<int>>&grid,int row,int col){
        set<int>used;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                int ele=grid[row+i][col+j];
                if(ele<1 || ele>9 || used.find(ele)!=used.end()) return false;
                
                used.insert(ele);

            }
        }

        int Rsum=grid[row][col]+grid[row][col+1]+grid[row][col+2];
        
        int Csum=grid[row][col]+grid[row+1][col]+grid[row+2][col];

        if(Rsum!=Csum) return false;


        for(int i=0;i<3;i++){
            if(grid[row+i][col]+grid[row+i][col+1]+grid[row+i][col+2]!=Rsum || grid[row+i][col]+grid[row+i][col+1]+grid[row+i][col+2]!=Csum) return false;
        }

        

        for(int i=0;i<3;i++){
            if(grid[row][col+i]+grid[row+1][col+i]+grid[row+2][col+i]!=Csum || grid[row][col+i]+grid[row+1][col+i]+grid[row+2][col+i]!=Rsum) return false;
        }

        int dsum1=grid[row][col]+grid[row+1][col+1]+grid[row+2][col+2];
        int dsum2=grid[row][col+2]+grid[row+1][col+1]+grid[row+2][col];

        if(dsum1!=dsum2 || dsum1!=Rsum || dsum1 !=Csum) return false;
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int ans=0;
        for(int i=0;i<=n-3;i++){
            for(int j=0;j<=m-3;j++){
                if(helper(grid,i,j)) ans++;
            }
        }
        return ans;
    }
};