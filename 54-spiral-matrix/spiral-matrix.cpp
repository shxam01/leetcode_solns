class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int total=m*n;
        int start_row=0;
        int start_col=0;
        int end_row=n-1;
        int end_col=m-1;
        vector<int>ans;
        while(ans.size()<total){
            for(int i=start_col;i<=end_col && ans.size()<total;i++){
                ans.push_back(matrix[start_row][i]);
                
            }
            start_row++;
            
            for(int i=start_row;i<=end_row && ans.size()<total;i++){
                ans.push_back(matrix[i][end_col]);
                // total--;
            }
            end_col--;
            for(int i=end_col;i>=start_col &&ans.size()<total;i--){
                ans.push_back(matrix[end_row][i]);
                // total--;
            }
            end_row--;
            for(int i=end_row;i>=start_row &&ans.size()<total;i--){
                ans.push_back(matrix[i][start_col]);
                // total--;
            }
            start_col++;
        }
        return ans;
    }
};