class Solution {
  public:
    vector<int> getMarks(vector<int> &l, vector<int> &r, vector<int> &rank) {
        int n = l.size();

        // prefix[i] = total number of valid marks
        // from interval 0 to i
        vector<long long> prefix(n);

        prefix[0] = (long long)r[0] - l[0] + 1;

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + 
                        (long long)r[i] - l[i] + 1;
        }

        vector<int> ans;

        for (int k : rank) {
            // Find first interval whose prefix count >= k
            int idx = lower_bound(prefix.begin(), prefix.end(), k) 
                      - prefix.begin();

            // Number of valid marks before this interval
            long long prev = (idx == 0) ? 0 : prefix[idx - 1];

            // Position of k inside this interval
            long long mark = (long long)l[idx] + (k - prev - 1);

            ans.push_back((int)mark);
        }

        return ans;
    }
};