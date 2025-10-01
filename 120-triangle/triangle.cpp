class Solution {
public:

    // typedef pair<int,pair<int,int>> p;
    
    // int bfs(vector<vector<int>>&grid,int mx,int n){
    //     priority_queue<p,vector<p>,greater<p>>pq;

    //     int dx[2]={1,1};
    //     int dy[2]={0,1};

    //     vector<vector<bool>>vis(n,vector<bool>(mx,false));

    //     vis[0][0]=true;

    //     pq.push({grid[0][0],{0,0}});

    //     while(!pq.empty()){
    //         auto [curr_sum,pos]=pq.top();
    //         auto [x,y]=pos;
    //         pq.pop();

    //         if(x==n-1) return curr_sum;

    //         for(int i=0;i<2;i++){
    //             int nx=x+dx[i];
    //             int ny=y+dy[i];

    //             if(nx<n && ny<mx && grid[nx][ny]!=1e7){
    //                 int new_sum=curr_sum+grid[nx][ny];
    //                 if(!vis[nx][ny]){
    //                     pq.push({new_sum,{nx,ny}});
    //                     vis[nx][ny]=true;
    //                 }
    //             }
    //         }
    //     }
    //     return -1;
    // }
    int n;
    
    int helper(vector<vector<int>>&triangle,int idx,int row,vector<vector<int>>&dp){

        if(row==n-1) return triangle[row][idx];

        // if(row>=n) return 1e7;

        if(dp[idx][row]!=-1e7) return dp[idx][row];

        int ans=1e7;
        
        ans=min(ans,helper(triangle,idx,row+1,dp) + triangle[row][idx]);

        ans=min(ans,helper(triangle,idx+1,row+1,dp) + triangle[row][idx]);

        return dp[idx][row]=ans;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        n=triangle.size();
        // int mx=INT_MIN;
        // for(auto &vec:triangle){
        //     int sz=vec.size();
        //     mx=max(mx,sz);
        // }

        // vector<vector<int>>new_triangle(triangle.size(),vector<int>(mx));

        // for(int i=0;i<triangle.size();i++){
        //     for(int j=0;j<mx;j++){
        //         if(j<triangle[i].size()){
        //             new_triangle[i][j]=triangle[i][j];
        //         }else{
        //             new_triangle[i][j]=1e7;
        //         }
        //     }
        // }
        // int n=new_triangle.size();
        // return bfs(new_triangle,mx,n);

        vector<vector<int>>dp(n,vector<int>(n,-1e7));

        return helper(triangle,0,0,dp);
    }
};