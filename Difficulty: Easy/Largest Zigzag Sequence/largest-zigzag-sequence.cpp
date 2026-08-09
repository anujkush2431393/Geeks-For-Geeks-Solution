class Solution {
public:
    int zigzagSequence(vector<vector<int>>& mat) {
        int n = mat.size();
        
        vector<int> dp(n);
        
        // First row
        for (int j = 0; j < n; j++)
            dp[j] = mat[0][j];
        
        for (int i = 1; i < n; i++) {
            vector<int> ndp(n, 0);
            
            for (int j = 0; j < n; j++) {
                int best = 0;
                
                // Choose previous row element from a different column
                for (int k = 0; k < n; k++) {
                    if (k != j)
                        best = max(best, dp[k]);
                }
                
                ndp[j] = mat[i][j] + best;
            }
            
            dp = ndp;
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};