class Solution {
  public:
    int countKdivPairs(vector<int>& arr, int k) {
        vector<int> rem(k, 0);
        int ans = 0;

        for (int x : arr) {
            int r = x % k;
            int need = (k - r) % k;
            ans += rem[need];
            rem[r]++;
        }

        return ans;
    }
};