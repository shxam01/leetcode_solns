    class Solution {
    public:
        vector<vector<int>> generateMatrix(int n) {
            vector<vector<int>>mat(n,vector<int>(n));

            int startRow=0;
            int startCol=0;
            int endRow=n-1;
            int endCol=n-1;

            int curr=1;
            while(startRow<=endRow && startCol<=endCol){
                for(int i=startCol;i<=endCol;i++){
                    mat[startRow][i]=curr;
                    curr++;
                }
                
                startRow++;
                for(int i=startRow;i<=endRow;i++){
                    mat[i][endCol]=curr;
                    curr++;
                }
                endCol--;
                for(int i=endCol;i>=startCol;i--){
                    mat[endRow][i]=curr;
                    curr++;
                }
                endRow--;
                for(int i=endRow;i>=startRow;i--){
                    mat[i][startCol]=curr;
                    curr++;
                }
                startCol++;
            }
            return mat;
        }
    };