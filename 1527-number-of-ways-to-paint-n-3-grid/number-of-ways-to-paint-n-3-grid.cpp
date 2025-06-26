class Solution {
public:
    vector<string>RowStates;

    const int mod=1e9+7;

    void generateRowStates(string curr, char prev,int curr_length,int max_length){
        if(curr_length==max_length){
            RowStates.push_back(curr);
            return;
        }

        for(auto ch:{'R','G','B'}){
            if(ch==prev) continue;
            generateRowStates(curr+ch,ch,curr_length+1,max_length);
        }
    }

    bool can_place(string &prev_state,string &curr_state){
        int sz=prev_state.size();

        for(int i=0;i<sz;i++){
            if(prev_state[i]==curr_state[i]){
                return false;
            }
        }
        return true;
    }

    int solve(int prev_state,int remain_rows,vector<vector<int>>&dp){
        if(remain_rows==0){
            return 1;
        }
        if(dp[prev_state][remain_rows]!=-1) return dp[prev_state][remain_rows];
        int ways=0;

        string prev=RowStates[prev_state];

        for(int i=0;i<RowStates.size();i++){
            if(i==prev_state) continue;

            string curr=RowStates[i];

            if(can_place(prev,curr)==false) continue;

            ways =(ways+solve(i,remain_rows-1,dp))%mod; 
        }
        return dp[prev_state][remain_rows]=ways;
    }



    int numOfWays(int n) {
        int ans=0;
        generateRowStates("",'#',0,3);
        int sz=RowStates.size();
        vector<vector<int>>dp(sz+1,vector<int>(n+1,-1));
        for(int i=0;i<RowStates.size();i++){
            ans =(ans+solve(i,n-1,dp))%mod;
        }
        return ans;
    }
};