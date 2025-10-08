class Solution {
public:
    typedef long long ll;
    long long putMarbles(vector<int>& weights, int k) {
        int n=weights.size();
        

        vector<ll>vec;


        for(int i=0;i<=n-2;i++){
            ll sum=weights[i]+weights[i+1];


            vec.push_back(sum);
        }

        sort(vec.begin(),vec.end());
        int sz=vec.size();
        int i=0;
        int j=sz-1;
        ll diff=0;
        
        while(i<=k-2 && j>=(sz-k+1)){
            diff +=vec[j]-vec[i];
            i++;
            j--;
        }
        return diff;
    }
};