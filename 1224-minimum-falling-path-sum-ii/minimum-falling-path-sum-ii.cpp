// class Solution {
// public:
//     int n,m;
//     #define ll long long
//     int dp[201][201];
//     int helper(vector<vector<int>>&grid,int row,int col){
//         if(row==n-1){
//             return grid[row][col];
//         }
//         if(dp[row][col]!=-1) return dp[row][col];
//         int ans=INT_MAX;
//         for(int j=0;j<m;j++){
//             // int next=grid[row][col]+helper(grid,row)
//             // int next;
//             if(j!=col){
//                 int next=helper(grid,row+1,j)+grid[row][col];
//                 ans=min(ans,next);
//             }
//         }
//         return dp[row][col]=ans;
//     }
//     int minFallingPathSum(vector<vector<int>>& grid) {
//         n=grid.size();
//         m=grid[0].size();
//         // vector<vector<vector<ll>>>dp(n+1,vector<vector<ll>>(m+1,vector<ll>(m+3,-1)));
//         // vector<vector<ll>>dp(n+1,vector<ll>(m+1,-1));
//         bool found=true;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(grid[i][j]!=0){
//                     found=false;
//                     break;
//                 }
//             }
//         }
//         if(found) return 0;
//          memset(dp,-1,sizeof(dp));
//         int ans=INT_MAX;
//         for(int i=0;i<m;i++){
//             ans=min(ans,helper(grid,0,i));
//         }
//         return ans;
//     }
// };
class Solution {
public:
    int n;
    
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        
        vector<vector<int>> t(n, vector<int>(n, INT_MAX));

        for (int col = 0; col < n; col++) {
            t[n - 1][col] = grid[n - 1][col];
        }

        for (int row = n - 2; row >= 0; row--) {
            for (int col = 0; col < n; col++) {
                int ans = INT_MAX;
                for (int nextCol = 0; nextCol < n; nextCol++) {
                    if (nextCol != col) {
                        ans = min(ans, t[row + 1][nextCol]);
                    }
                }
                t[row][col] = grid[row][col] + ans;
            }
        }

        int result = INT_MAX;
        for (int col = 0; col < n; col++) {
            result = min(result, t[0][col]);
        }

        return result;
    }
};
