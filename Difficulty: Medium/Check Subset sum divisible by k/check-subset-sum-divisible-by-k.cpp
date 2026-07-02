class Solution {
  public:
    bool divisibleByK(vector<int>& arr, int k) {
        vector<bool> dp(k, false);
        
        for (int num : arr) {
            vector<bool> temp = dp; // snapshot of previous reachable remainders
            int r = num % k;
            
            // starting a new subset with this element alone
            dp[r] = true;
            
            // extend previously reachable remainders by adding this element
            for (int rem = 0; rem < k; rem++) {
                if (temp[rem]) {
                    int newRem = (rem + num) % k;
                    dp[newRem] = true;
                }
            }
        }
        
        return dp[0];
    }
};