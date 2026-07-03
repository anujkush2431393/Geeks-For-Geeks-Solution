class Solution {
  public:
    int waysToIncreaseLCSBy1(string &s1, string &s2) {
        int n = s1.size(), m = s2.size();

        vector<vector<int>> pre(n + 1, vector<int>(m + 1, 0));
        vector<vector<int>> suf(n + 1, vector<int>(m + 1, 0));

        // Forward LCS
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1])
                    pre[i][j] = pre[i - 1][j - 1] + 1;
                else
                    pre[i][j] = max(pre[i - 1][j], pre[i][j - 1]);
            }
        }

        // Reverse LCS
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (s1[i] == s2[j])
                    suf[i][j] = suf[i + 1][j + 1] + 1;
                else
                    suf[i][j] = max(suf[i + 1][j], suf[i][j + 1]);
            }
        }

        int lcs = pre[n][m];
        int ans = 0;

        for (int i = 0; i <= n; i++) {
            bool used[26] = {false};

            for (int j = 0; j < m; j++) {
                int ch = s2[j] - 'a';

                if (used[ch]) continue;

                if (pre[i][j] + 1 + suf[i][j + 1] == lcs + 1) {
                    ans++;
                    used[ch] = true;
                }
            }
        }

        return ans;
    }
};