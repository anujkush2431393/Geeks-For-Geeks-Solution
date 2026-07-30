class Solution {
  public:
    int maxSubsetXOR(vector<int> &arr) {
        int n = arr.size();
        int idx = 0;

        // Build XOR basis using Gaussian Elimination
        for (int bit = 31; bit >= 0; bit--) {
            int pivot = -1;

            for (int i = idx; i < n; i++) {
                if (arr[i] & (1 << bit)) {
                    pivot = i;
                    break;
                }
            }

            if (pivot == -1)
                continue;

            swap(arr[idx], arr[pivot]);

            for (int i = 0; i < n; i++) {
                if (i != idx && (arr[i] & (1 << bit))) {
                    arr[i] ^= arr[idx];
                }
            }

            idx++;
        }

        int ans = 0;
        for (int x : arr) {
            ans = max(ans, ans ^ x);
        }

        return ans;
    }
};