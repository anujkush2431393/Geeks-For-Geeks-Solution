class Solution {
public:
    vector<int> largestSquare(vector<vector<int>>& mat,
                               vector<vector<int>>& queries,
                               int k) {
        
        int n = mat.size();
        int m = mat[0].size();

        // 2D Prefix Sum
        vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                pref[i][j] = mat[i - 1][j - 1]
                           + pref[i - 1][j]
                           + pref[i][j - 1]
                           - pref[i - 1][j - 1];
            }
        }

        // Function to count 1s in rectangle
        auto getSum = [&](int r1, int c1, int r2, int c2) {
            // Convert to prefix-sum coordinates
            r1++;
            c1++;
            r2++;
            c2++;

            return pref[r2][c2]
                 - pref[r1 - 1][c2]
                 - pref[r2][c1 - 1]
                 + pref[r1 - 1][c1 - 1];
        };

        vector<int> ans;

        for (auto &q : queries) {
            int i = q[0];
            int j = q[1];

            // Maximum possible radius
            int maxRadius = min({
                i,
                j,
                n - 1 - i,
                m - 1 - j
            });

            // Check if even 1x1 square is valid
            if (mat[i][j] > k) {
                ans.push_back(-1);
                continue;
            }

            int low = 0;
            int high = maxRadius;
            int best = 0;

            // Binary search for largest valid radius
            while (low <= high) {
                int mid = low + (high - low) / 2;

                int r1 = i - mid;
                int c1 = j - mid;
                int r2 = i + mid;
                int c2 = j + mid;

                int ones = getSum(r1, c1, r2, c2);

                if (ones <= k) {
                    best = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            // Side length = 2 * radius + 1
            ans.push_back(2 * best + 1);
        }

        return ans;
    }
};