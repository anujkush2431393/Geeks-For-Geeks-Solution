class Solution {
    vector<int> bit;

    void update(int idx, int val) {
        while (idx < bit.size()) {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    int query(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += bit[idx];
            idx -= idx & -idx;
        }
        return sum;
    }

public:
    int countSubstring(string& s) {
        int n = s.size();

        vector<int> pref(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            pref[i] = pref[i - 1] + (s[i - 1] == '1' ? 1 : -1);
        }

        vector<int> vals = pref;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        bit.assign(vals.size() + 2, 0);

        long long ans = 0;

        for (int x : pref) {
            int idx = lower_bound(vals.begin(), vals.end(), x) - vals.begin() + 1;
            ans += query(idx - 1);
            update(idx, 1);
        }

        return (int)ans;
    }
};