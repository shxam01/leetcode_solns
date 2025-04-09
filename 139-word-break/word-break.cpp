class Solution {
public:
    int n;
    int dp[301];
    bool helper(int idx,string s,set<string> &worddict){
        if(idx>=n) return true;
        
        if(dp[idx]!=-1) return dp[idx];
        bool ans=false;
        for(int l=1;l<=n;l++){
            string str=s.substr(idx,l);
            if(worddict.find(str)!=worddict.end()){
                if(helper(idx+l,s,worddict)){
                    return ans=true;
                }
            }
        }
        return dp[idx]=ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n=s.size();
        memset(dp,-1,sizeof(dp));
        set<string>worddict(wordDict.begin(),wordDict.end());
        return helper(0,s,worddict);
    }
};