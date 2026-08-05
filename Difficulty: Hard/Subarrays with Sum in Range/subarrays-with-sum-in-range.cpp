class Solution {
    long long countAtMost(vector<int>& arr, long long k) {
        long long ans = 0, sum = 0;
        int left = 0;

        for (int right = 0; right < arr.size(); right++) {
            sum += arr[right];

            while (sum > k) {
                sum -= arr[left++];
            }

            ans += (right - left + 1);
        }

        return ans;
    }

  public:
    int countSubarray(vector<int>& arr, int l, int r) {
        return (int)(countAtMost(arr, r) - countAtMost(arr, (long long)l - 1));
    }
};