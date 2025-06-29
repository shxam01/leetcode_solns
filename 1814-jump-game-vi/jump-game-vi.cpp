// class Solution {
// public:
//     int n;
//     typedef long long ll;
//     ll helper(vector<int>&nums,int k,int idx){
        
//         priority_queue<pair<ll,int>>pq;

//         pq.push({nums[0],0});

//         vector<ll>dist(n,LLONG_MIN);

//         dist[idx]=nums[idx];

//         while(!pq.empty()){
//             auto [curr_score,curr_idx]=pq.top();

//             pq.pop();

//             if(curr_idx==n-1) return curr_score;

//             if(curr_score<dist[curr_idx]) continue;

//             for(int i=curr_idx+1;i<=min(n-1,curr_idx+k);i++){
//                 if( curr_score+nums[i]>dist[i]){
//                     dist[i]=curr_score+nums[i];
//                     pq.push({dist[i],i});
//                 }
//             }
//         }
//         return dist[n-1];
//     }
//     int maxResult(vector<int>& nums, int k) {
//         n=nums.size();

       

//         return helper(nums,k,0);
//     }
// };

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        deque<int> dq{0}; // Stores indices in decreasing order of dp values
        
        for (int i = 1; i < n; ++i) {
            // Remove indices out of the current window [i-k, i]
            while (!dq.empty() && dq.front() < i - k) {
                dq.pop_front();
            }
            
            dp[i] = dp[dq.front()] + nums[i];
            
            // Maintain deque order by removing indices with lower or equal dp values
            while (!dq.empty() && dp[i] >= dp[dq.back()]) {
                dq.pop_back();
            }
            
            dq.push_back(i);
        }
        return dp[n-1];
    }
};