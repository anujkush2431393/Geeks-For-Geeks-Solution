class Solution {
  public:
    long long countLessEqual(vector<int>& arr, int x) {
        int n = arr.size();
        long long cnt = 0;

        for (int i = 0; i < n - 2; i++) {
            int j = i + 1, k = n - 1;

            while (j < k) {
                if (arr[i] + arr[j] + arr[k] <= x) {
                    cnt += (k - j);
                    j++;
                } else {
                    k--;
                }
            }
        }

        return cnt;
    }

    int countTriplets(vector<int> &arr, int l, int r) {
        sort(arr.begin(), arr.end());

        // Triplets with sum in [l, r]
        // = triplets with sum <= r - triplets with sum < l
        long long ans = countLessEqual(arr, r) -
                        countLessEqual(arr, l - 1);

        return (int)ans;
    }
};