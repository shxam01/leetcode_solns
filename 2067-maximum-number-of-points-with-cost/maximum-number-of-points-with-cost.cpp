class Solution {
public:
    int n,m;
    #define ll long long
    
    long long helper(vector<vector<int>>&points,int row,int col,vector<vector<long long>>&dp){
        if(row==n-1){
            return points[row][col];
        }
        if(dp[row][col]!=-1) return dp[row][col];
        //lets start by taking the current element
        ll sum=INT_MIN;
        
        for(int i=0;i<m;i++){
            // sum=max(sum,helper(points,row+1,i)+points[row][column]-abs(i-column));
            ll next= points[row][col]+helper(points,row+1,i,dp)-abs(col-i);
            sum=max(sum,next);
        }
        return dp[row][col]=sum;
    }
    long long maxPoints(vector<vector<int>>& points) {
       n=points.size();
       m=points[0].size();
       vector<long long>prev(m);
       for(int i=0;i<m;i++){
        prev[i]=points[0][i];
       }
       for(int i=1;i<n;i++){

        vector<long long>left(m,0);
        vector<long long>right(m,0);
        left[0]=prev[0];
        for(int j=1;j<m;j++){
            left[j]=max(prev[j],left[j-1]-1);
        }
        right[m-1]=prev[m-1];
        for(int j=m-2;j>=0;j--){
            right[j]=max(prev[j],right[j+1]-1);
        }
        vector<long long>curr(m);
        for(int j=0;j<m;j++){
            curr[j]=points[i][j]+max(left[j],right[j]);
        }
        prev=curr;
       }
       return *max_element(begin(prev),end(prev));
    }
};