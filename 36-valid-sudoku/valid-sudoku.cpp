class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();

        for(int row=0;row<n;row++){
            set<char>st;
            for(int col=0;col<m;col++){
                if(board[row][col]=='.') continue;
                if(st.find(board[row][col])!=st.end()) return false;
                st.insert(board[row][col]);

                
            }
        }

        for(int col=0;col<m;col++){
            set<char>st;
            for(int row=0;row<n;row++){
                if(board[row][col]=='.') continue;
                if(st.find(board[row][col])!=st.end()) return false;
                st.insert(board[row][col]);
            }
        }

        for (int i = 0; i < n; i += 3) {
            for (int j = 0; j < m; j += 3) {
                set<char> st;
                for (int k = i; k < i + 3; k++) {
                    for (int l = j; l < j + 3; l++) {
                        if (board[k][l] == '.') continue;
                        if (st.find(board[k][l]) != st.end()) return false;
                        st.insert(board[k][l]);
                    }
                }
            }
        }

        

        
        return true;
    }
};