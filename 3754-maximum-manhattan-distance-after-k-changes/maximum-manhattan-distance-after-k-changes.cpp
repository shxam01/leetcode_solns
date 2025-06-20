class Solution {
public:
    
    int maxDistance(string s, int k) {
        int maxD=0;
        int east=0;
        int west=0;
        int north=0;
        int south=0;
        int ans=0;
        int n=s.size();
        for(int i=0;i<n;i++){

            if(s[i]=='E') east++;
            else if(s[i]=='W') west++;
            else if(s[i]=='N') north++;
            else if(s[i]=='S') south++;

            int currMD=abs(east-west) + abs(north-south);
            int steps=i+1;
            int wasted=steps-currMD;
            int extra=0;
            if(wasted!=0){
                extra=min(2*k,wasted);
            }

            int finalCURRMD=  currMD+extra;
            ans=max(ans,finalCURRMD);
        }

        return ans;
    }
};