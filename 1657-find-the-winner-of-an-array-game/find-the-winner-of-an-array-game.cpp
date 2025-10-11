class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n=arr.size();
        int mx=*max_element(arr.begin(),arr.end());
        if(k>=n) return mx;

        int winner=arr[0];
        int win=0;

        for(int i=1;i<n;i++){

            if(arr[i]>winner){
                winner=arr[i];
                win=1;
            }else{
                win++;
            }

            if(win==k || winner==mx) return winner;

        }
        return -1;
    }
};