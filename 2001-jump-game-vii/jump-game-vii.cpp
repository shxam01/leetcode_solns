class Solution {
public:
    // int n;
    // int dp[100001];
    // bool helper(string s,int minJump,int maxJump, int idx,vector<bool>&vis){
    //     if(idx>=n-1) return true;

    //     if(dp[idx]!=-1) return dp[idx];

    //     queue<int>q;

    //     q.push(idx);

    //     vis[idx]=true;

    //     while(!q.empty()){
    //         auto curr_idx=q.front();

    //         q.pop();

    //         if(curr_idx==n-1) return dp[idx]=1;

    //         for(int next=idx+1;next<n;next++){
    //             if(!vis[next] && (next>=curr_idx+minJump && next<=min(curr_idx+maxJump,n-1)) && s[next]=='0'){
    //                 vis[next]=true;
    //                 q.push(next);
    //             }
    //         }
    //     }
    //     return dp[idx]=0;
    // }
    // bool canReach(string s, int minJump, int maxJump) {
    //     n=s.size();

    //     vector<bool>vis(n,false);

    //     memset(dp,-1,sizeof(dp));

    //     return helper(s,minJump,maxJump,0,vis)==1?true:false;
    // }

        bool canReach(string s, int minJ, int maxJ) {
        int n = s.size(), pre = 0;
        vector<bool> dp(n, false);
        dp[0] = true;
        for (int i = 1; i < n; ++i) {
            if (i >= minJ)
                pre += dp[i - minJ];
            if (i > maxJ)
                pre -= dp[i - maxJ - 1];
            dp[i] = pre > 0 && s[i] == '0';
        }
        return dp[n - 1];
    }
};