class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n=arr.size();
        int one_fourth=n/4;
        unordered_map<int,int>mp;
        for(auto &ele:arr){
            mp[ele]++;
            if(mp[ele]>one_fourth){
                return ele;
            }
        }
        return -1;
    }
};