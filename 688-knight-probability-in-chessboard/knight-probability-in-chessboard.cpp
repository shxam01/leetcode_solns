class Solution {
public:
    bool valid(int x, int y, int n) {
        return x >= 0 && x < n && y >= 0 && y < n;
    }
    
    double helper(int n, int k, int row, int column,vector<vector<vector<double>>>&dp) {
        if(k==0) 
          return 1.0;
        vector<vector<int>> moves = {{2,1}, {2,-1}, {1,2}, {1,-2}, {-1,-2}, {-2,-1}, {-2,1}, {-1,2}};
        // int move = 0;
        if(dp[k][row][column]!=-1.0) return dp[k][row][column];
        double prob=0.0;
        for (int i = 0; i < 8; i++) {
            int nr = row + moves[i][0];
            int nc = column + moves[i][1];
            if (valid(nr, nc, n)) {
                prob += helper(n, k-1, nr, nc,dp);
            }
        }
        return dp[k][row][column]=prob/8.0;
    }
    
    double knightProbability(int n, int k, int row, int column) {
        // int moves = helper(n, k, row, column);
        vector<vector<vector<double>>>dp(k+1,vector<vector<double>>(n+1,vector<double>(n+1,-1.0)));
        double ans = helper(n,k,row,column,dp);
        
        return ans;
    }
};