class Solution {
public:
    int maxTask(vector<int>& h, vector<int>& l) {
        int n = h.size();

        // dp0 = maximum tasks when previous day had no task
        // dp1 = maximum tasks when previous day had a task
        int dp0 = 0;
        int dp1 = 0;

        for (int i = 0; i < n; i++) {
            int new_dp0 = max(dp0, dp1);

            // High effort can be done only if previous day had no task
            int high = dp0 + h[i];

            // Low effort can always be done
            int low = max(dp0, dp1) + l[i];

            int new_dp1 = max(high, low);

            dp0 = new_dp0;
            dp1 = new_dp1;
        }

        return max(dp0, dp1);
    }
};