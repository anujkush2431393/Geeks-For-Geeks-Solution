class Solution {
  public:
    int find(vector<int>& arr) {
        long long x = 0;

        for (int i = arr.size() - 1; i >= 0; i--) {
            x = (x + arr[i] + 1) / 2;   // ceil((x + arr[i]) / 2)
        }

        return x == 0 ? 1 : (int)x;
    }
};