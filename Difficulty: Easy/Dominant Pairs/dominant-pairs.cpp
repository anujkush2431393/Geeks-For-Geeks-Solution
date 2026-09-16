class Solution {
  public:
    int dominantPairs(vector<int> &arr) {
        int n = arr.size();
        int half = n / 2;

        vector<int> second(arr.begin() + half, arr.end());
        sort(second.begin(), second.end());

        int count = 0;

        for (int i = 0; i < half; i++) {
            // Find first element where 5 * second[j] > arr[i]
            int left = 0, right = half;

            while (left < right) {
                int mid = left + (right - left) / 2;

                if ((long long)5 * second[mid] <= arr[i])
                    left = mid + 1;
                else
                    right = mid;
            }

            count += left;
        }

        return count;
    }
};