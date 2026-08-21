class Solution {
  public:
    int transform(string &s1, string &s2) {
        if (s1.length() != s2.length())
            return -1;

        // Check if both strings contain the same characters
        string a = s1, b = s2;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        if (a != b)
            return -1;

        int i = s1.length() - 1;
        int j = s2.length() - 1;
        int ans = 0;

        // Match characters from the end
        while (i >= 0) {
            if (s1[i] == s2[j]) {
                i--;
                j--;
            } else {
                // Move this character to front
                ans++;
                i--;
            }
        }

        return ans;
    }
};