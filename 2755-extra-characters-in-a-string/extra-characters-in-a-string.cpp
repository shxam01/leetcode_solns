class Solution {
public:
    int n;
    int dp[51];
    int helper(int idx,set<string>&dict,string &s){
        if(idx>=n) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int mn=n;
        string crnt="";
        for(int i=idx;i<n;i++){
            crnt.push_back(s[i]);
            int crnt_extra=(dict.find(crnt)==dict.end())?crnt.size():0;
            int next_xtra=helper(i+1,dict,s);
            int total_extra=crnt_extra+next_xtra;
            mn=min(mn,total_extra);
        }
        return dp[idx]=mn;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        n=s.length();
        set<string>dict(dictionary.begin(),dictionary.end());
        memset(dp,-1,sizeof(dp));
        auto res=helper(0,dict,s);
        return res;
    }
};