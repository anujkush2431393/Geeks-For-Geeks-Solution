class Solution {
  public:
    int largestArea(int n, int m, vector<vector<int>> &arr) {
        vector<int> rows, cols;

        for (auto &cell : arr) {
            rows.push_back(cell[0]);
            cols.push_back(cell[1]);
        }

        sort(rows.begin(), rows.end());
        sort(cols.begin(), cols.end());

        int maxRows = 0, maxCols = 0;

        int prev = 0;
        for (int r : rows) {
            maxRows = max(maxRows, r - prev - 1);
            prev = r;
        }
        maxRows = max(maxRows, n - prev);

        prev = 0;
        for (int c : cols) {
            maxCols = max(maxCols, c - prev - 1);
            prev = c;
        }
        maxCols = max(maxCols, m - prev);

        return maxRows * maxCols;
    }
};