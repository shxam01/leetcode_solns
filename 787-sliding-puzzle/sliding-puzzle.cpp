class Solution {
public:
    int position(string &board){
        for(int i=0;i<6;i++){
            if(board[i]=='0') return i;
        }
        return -1;
    }
    string target="123450";
    
    int bfs(string board,unordered_map<int,vector<int>>&mp){
        unordered_set<string>st;

        st.insert(board);
        queue<string>q;

        q.push(board);

        int level=0;

        while(!q.empty()){
            

            int n=q.size();

            while(n--){
                auto str=q.front();
                q.pop();

                if(str==target) return level;

                auto curr_pos=position(str);

                for(auto &can_move_to:mp[curr_pos]){
                    string curr_state=str;

                    swap(curr_state[can_move_to],curr_state[curr_pos]);

                    if(st.find(curr_state)==st.end()){
                        st.insert(curr_state);
                        q.push(curr_state);
                    }

                }
            }
            level++;
        }
        return -1;
    }
    
    
    int slidingPuzzle(vector<vector<int>>& board) {
        unordered_map<int,vector<int>>mp;
        mp[0]={1,3};
        mp[1]={0,2,4};
        mp[2]={1,5};
        mp[3]={0,4};
        mp[4]={3,5,1};
        mp[5]={2,4};

        string boardd="";
        for(int i=0;i<2;i++){
            for(int j=0;j<3;j++){
                boardd +=to_string(board[i][j]);
            }
        }
        int res=bfs(boardd,mp);
        return res==-1?-1:res;
    }
};