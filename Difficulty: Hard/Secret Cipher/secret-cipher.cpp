class Solution {
  public:
    string compress(string &s) {
        int n = s.size();

        // LPS / Prefix Function
        vector<int> lps(n, 0);

        for (int i = 1; i < n; i++) {
            int j = lps[i - 1];

            while (j > 0 && s[i] != s[j])
                j = lps[j - 1];

            if (s[i] == s[j])
                j++;

            lps[i] = j;
        }

        string ans = "";

        // Build answer from right to left
        for (int i = n - 1; i >= 0; i--) {

            // A '*' can replace the second half only
            // when prefix == suffix and the whole
            // string is made by repeating a prefix.
            if (i % 2 == 1) {
                int len = i + 1;
                int border = lps[i];

                if (border >= len / 2 &&
                    len % (2 * (len - border)) == 0) {

                    ans += '*';
                    i = i / 2 + 1;
                    continue;
                }
            }

            ans += s[i];
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};