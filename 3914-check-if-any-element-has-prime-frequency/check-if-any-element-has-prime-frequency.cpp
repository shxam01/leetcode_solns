class Solution {
public:
    bool is_prime(int n) {
        if (n <= 1) return false;
        if (n == 2) return true;
        if (n % 2 == 0) return false;
        
        for (int i = 3; i * i <= n; i += 2) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
    
    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int, int> freq;
        
        // Count frequencies
        for (auto& ele : nums) {
            freq[ele]++;
        }
        
        // Check if any frequency is prime
        for (auto& it : freq) {
            int frequency = it.second;  // Fixed: it.second instead of it->second
            if (is_prime(frequency)) {
                return true;
            }
        }
        
        return false;  // Return false if no prime frequencies found
    }
};