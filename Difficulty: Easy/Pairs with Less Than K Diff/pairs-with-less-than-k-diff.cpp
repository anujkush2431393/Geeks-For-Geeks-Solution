class Solution {
  public:
    int countPairs(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());

        int n = arr.size();
        int j = 0;
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            while (j < n && arr[j] - arr[i] < k)
                j++;

            ans += (j - i - 1);
        }

        return (int)ans;
    }
};