class Solution {
  public:
    string findLongestWord(string &s, vector<string> &d) {
        int n = s.size();

        // next[i][c] = first position >= i where character c occurs
        vector<array<int, 26>> next(n + 1);

        for (int c = 0; c < 26; c++)
            next[n][c] = -1;

        for (int i = n - 1; i >= 0; i--) {
            next[i] = next[i + 1];
            next[i][s[i] - 'a'] = i;
        }

        string ans = "";

        for (string &word : d) {
            int pos = 0;
            bool possible = true;

            for (char ch : word) {
                if (pos > n || next[pos][ch - 'a'] == -1) {
                    possible = false;
                    break;
                }

                pos = next[pos][ch - 'a'] + 1;
            }

            if (possible) {
                if (word.size() > ans.size() ||
                    (word.size() == ans.size() && word < ans)) {
                    ans = word;
                }
            }
        }

        return ans;
    }
};