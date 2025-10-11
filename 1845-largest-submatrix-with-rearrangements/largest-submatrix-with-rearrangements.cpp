class Solution {
public:
    int n,m;
   
    int largestSubmatrix(vector<vector<int>>& matrix) {
        n=matrix.size();
        m=matrix[0].size();
        int maxArea=0;
        vector<int>one_count(m,0);
        for(int row=0;row<n;row++){
            
            for(int col=0;col<m;col++){
                if(matrix[row][col]==1){
                    one_count[col] +=1;
                }else{ // continuous one ki wjh se hi aa skta 
                    one_count[col]=0;
                }
            }
            
        

            vector<int>temp=one_count;

            sort(temp.rbegin(),temp.rend());

            
          
            for(int j=0;j<m;j++){
                if(temp[j]==0) break;
                int width=j+1;
                int height=temp[j];
                int area=height*width;
                maxArea=max(maxArea,area);
            }
        }
        return maxArea;
    }
};