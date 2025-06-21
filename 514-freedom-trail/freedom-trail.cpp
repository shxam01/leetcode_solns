class Solution {
public:
    int sz;
    int countsteps(int ringindex,int i,int ring_length){
        int distance=abs(i-ringindex);
        int wraparound=ring_length-distance;

        return min(distance,wraparound);
    }

    int solve(int ringindex,int kindex, string &ring, string &key,vector<vector<int>>&dp){
        
        if(kindex>=key.length()) return 0;
        if(dp[ringindex][kindex]!=-1) return dp[ringindex][kindex];
        int res=INT_MAX;
        for(int i=0;i<ring.length();i++){
            if(ring[i]==key[kindex]){
                int steps=1+countsteps(ringindex,i,sz);
                int totalsteps=steps+solve(i,kindex+1,ring,key,dp);
                res=min(res,totalsteps);
            }
        }
        return dp[ringindex][kindex]=res;
    }
    int findRotateSteps(string ring, string key) {
         int szz=key.length();
         sz=ring.length();
         vector<vector<int>>dp(sz+1,vector<int>(szz+1,-1));
         return solve(0,0,ring,key,dp);
    }
};