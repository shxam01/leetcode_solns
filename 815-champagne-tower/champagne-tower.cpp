class Solution {
public:
    double dp[101][101];
    double helper(int i,int j,int poured){
        if(i<0 || j<0 || i<j){
                return 0.0;
        }
        if(i==0 && j==0) return poured;
        if(dp[i][j]!=-1.0) return dp[i][j];
        double left_up=(helper(i-1,j,poured)-1)/2.0;
        double right_up=(helper(i-1,j-1,poured)-1)/2.0;
        if(left_up<0.0){
            left_up=0.0;
        }
        if(right_up<0.0){
            right_up=0.0;
        }
        return dp[i][j]=left_up+right_up;
    }
    double champagneTower(int poured, int query_row, int query_glass) {
        for(int i=0;i<101;i++){
            for(int j=0;j<101;j++){
                dp[i][j]=-1.0;
            }
        }
        if(query_row==0 && query_glass==0){
            return poured>0?1.0:0.0;
        }
        return min(1.0,helper(query_row,query_glass,poured));
    }
};