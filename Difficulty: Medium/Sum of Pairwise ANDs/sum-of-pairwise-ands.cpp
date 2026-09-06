class Solution {
  public:
    long long pairAndSum(vector<int> &arr) {
        int n = arr.size();
        long long ans = 0;

        for (int bit = 0; bit < 31; bit++) {
            long long cnt = 0;

            // Count elements having this bit set
            for (int x : arr) {
                if (x & (1 << bit)) {
                    cnt++;
                }
            }

            // Number of pairs having this bit set
            long long pairs = cnt * (cnt - 1) / 2;

            // Add contribution of this bit
            ans += pairs * (1LL << bit);
        }

        return ans;
    }
};