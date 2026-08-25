class Solution {
public:
    int minMoves(vector<int>& arr) {
        int n = arr.size();

        // table to store the length of the consecutive subsequence ending at each number
        // Since elements are 1 to n, size n + 1 is sufficient
        vector<int> dp(n + 1, 0);
        int max_len = 0;

        for (int num : arr) {
            // The length of the sequence ending at 'num' depends on 'num - 1'
            dp[num] = dp[num - 1] + 1;

            // Keep track of the maximum length found
            max_len = max(max_len, dp[num]);
        }

        // Minimum moves is total elements minus the max length left untouched
        return n - max_len;
    }
};
