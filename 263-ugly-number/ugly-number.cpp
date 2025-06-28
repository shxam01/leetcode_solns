class Solution {
public:
    bool isUgly(int n) {
        if(n<=0) return false;
        if(n<=1) return true;

        int prime[]={2,3,5};

        for(int i=0;i<3;i++){
            while(n%prime[i]==0){
                n/=prime[i];
            }
        }
        return n==1;
    }
};