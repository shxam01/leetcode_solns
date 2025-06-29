class Solution {
public:
    int n;
    vector<int> memo;     // -1: uncomputed, 0: false, 1: true
    vector<bool> visiting; // Track current path for cycle detection
    
    bool helper(vector<int>& arr, int idx) {
        if(idx < 0 || idx >= n) return false;
        
        if(memo[idx] != -1) return memo[idx];  // Already computed
        if(visiting[idx]) return false;        // Cycle detected
        
        if(arr[idx] == 0) return memo[idx] = 1;
        
        visiting[idx] = true;  // Mark as currently visiting
        
        int jump_length = arr[idx];
        bool result = false;
        
        // Try both directions
        if(idx - jump_length >= 0) {
            result |= helper(arr, idx - jump_length);
        }
        if(idx + jump_length < n) {
            result |= helper(arr, idx + jump_length);
        }
        
        visiting[idx] = false;  // Unmark when done
        return memo[idx] = result;
    }
    
    bool canReach(vector<int>& arr, int start) {
        n = arr.size();
        memo.assign(n, -1);
        visiting.assign(n, false);
        return helper(arr, start);
    }
};