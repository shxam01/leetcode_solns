class Solution {
public:
   
    int bestClosingTime(string customers) {
        // unordered_map<char,vector<int>>mp;

        int n=customers.size();

        vector<int>rightY(n+1,0);
        vector<int>leftN(n+1,0);

        // rightY[n-1]=(customers[n-1]=='Y')?1:0;

        for(int i=n-1;i>=0;i--){
            auto curr=customers[i];

            rightY[i]=rightY[i+1]+((curr=='Y')?1:0);
        }

        for(int i=1;i<=n;i++){
            leftN[i]=leftN[i-1]+((customers[i-1]=='N')?1:0);
        }

        int mn=INT_MAX;
        int min_index=0;

        for(int i=0;i<=n;i++){
            int penalty=rightY[i]+leftN[i];

            if(penalty<mn){
                mn=penalty;
                min_index=i;
            }
        }

        return min_index;



    }
};