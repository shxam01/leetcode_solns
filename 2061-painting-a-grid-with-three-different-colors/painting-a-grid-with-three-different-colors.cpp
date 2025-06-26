class Solution {
public:
//    str="RGB";
    vector<string>colState;

    int mod=1e9+7;

    void colStates(string curr,char prev,int m,int l){
        if(l==m){
            colState.push_back(curr);
            return;
        }
        for(char ch:{'R','G','B'}){
            if(ch==prev) continue;
            colStates(curr+ch,ch,m,l+1);
        }
    }


    bool can_place(string &prev_state,string &curr){
        int sz=prev_state.size();
        for(int i=0;i<sz;i++){
            if(prev_state[i]==curr[i]){
                return false;
            }
        }
        return true;
    }

    


    int solve(int prev_state_index,int remain_cols,vector<vector<int>>&dp){
        if(remain_cols==0){
            return 1;
        }
        if(dp[prev_state_index][remain_cols]!=-1) return dp[prev_state_index][remain_cols];
        int ways=0;
        string prev_state=colState[prev_state_index];

        for(int i=0;i<colState.size();i++){
            if(i==prev_state_index) continue;

            string curr=colState[i];

            bool flag=true;

            if(can_place(prev_state,curr)==false) continue;
            ways =(ways+solve(i,remain_cols-1,dp))%mod;
        }
        return dp[prev_state_index][remain_cols]=ways;
    }

    int colorTheGrid(int m, int n) {
        int result=0;
        colStates("",'#',m,0);
        int sz=colState.size();
        vector<vector<int>>dp(sz+1,vector<int>(n+1,-1));
        for(int i=0;i<colState.size();i++){
            result =(result+solve(i,n-1,dp))%mod;
        }

        return result;


    }
};