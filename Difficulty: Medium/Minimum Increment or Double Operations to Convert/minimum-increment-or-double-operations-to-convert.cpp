class Solution {
  public:
    int countMinOperations(vector<int>& arr) {
        int increments = 0;
        int doubles = 0;

        for (int x : arr) {
            int cnt = 0;
            while (x > 0) {
                if (x & 1) increments++;
                x >>= 1;
                if (x) cnt++;
            }
            doubles = max(doubles, cnt);
        }

        return increments + doubles;
    }
};