typedef long long ll;
#define mod 1000000007

class Solution {
public:
    int  givrev(int x){
        if(x<10){
            return x*10;
        }
        return ((x%10)*10)+(x/10);
    }
    int countPalindromes(string s) {
        vector<ll>forwardcnt(10,0);
        vector<ll>backwardcnt(10,0);
        vector<ll>subfront(100,0);
        vector<ll>subback(100,0);
        ll ans=0;
        for(int i=s.size()-1;i>=0;i--){
            int x=s[i]-'0';
            for(int j=0;j<10;j++){
                if(backwardcnt[j]>0){
                    subback[x*10+j]+=backwardcnt[j];
                }
            }
            backwardcnt[x]++;
        }
        for(int i=0;i<s.size();i++){
            int x=s[i]-'0';
            backwardcnt[x]--;
            for(int j=0;j<10;j++){
                if(backwardcnt[j]>0){
                    subback[x*10+j]-=backwardcnt[j];
                }
            }

            for(int j=0;j<100;j++){
                ans+=subfront[j]*subback[givrev(j)];
                ans%=mod;
            }
            
            for(int j=0;j<10;j++){
                if(forwardcnt[j]>0){
                    subfront[j*10+x]+=forwardcnt[j];
                }
            }
            forwardcnt[x]++;
        }
        return ans;
    }
};