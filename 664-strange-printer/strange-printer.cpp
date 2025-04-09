class Solution {
public:
   int n;
   int dp[101][101];
    int helper(int l,int r,string &s){
        if(l>r) return 0;
        if(l==r) return 1;
        
        int i=l+1;
        if(i>r) return dp[l][r];
        if(dp[l][r]!=-1) return dp[l][r];
        while(i<=r && s[i]==s[l]){
            i++;
        } 
        int basic=1+helper(i,r,s);
        int ans=basic;
        
        // int j=i;
        for(int j=i;j<=r;j++){
            if(s[j]==s[l]){
                int ans1=helper(i,j-1,s)+helper(j,r,s);
                ans=min(ans1,ans);
            }
        }
        return dp[l][r]=ans;
    }
    int strangePrinter(string s) {
        n=s.size();
        memset(dp,-1,sizeof(dp));
        return helper(0,n-1,s);
    }
};