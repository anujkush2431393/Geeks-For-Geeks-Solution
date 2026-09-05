class Solution {
  public:
    int longestSubseq(vector<int>& arr) {
        unordered_map<int, int> dp;
        int ans = 1;

        for (int x : arr) {
            int prev = max(dp[x - 1], dp[x + 1]);

            dp[x] = max(dp[x], prev + 1);

            ans = max(ans, dp[x]);
        }

        return ans;
    }
};