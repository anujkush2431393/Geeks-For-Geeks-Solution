class Solution {
  public:
    static const int MOD = 1000000007;

    long long power(long long a, long long b) {
        long long res = 1;
        a %= MOD;
        while (b) {
            if (b & 1) res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }

    int minOperations(vector<int> &b) {
        int n = b.size();
        vector<bool> vis(n, false);
        map<int, int> mp;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int len = 0;
                int cur = i;
                while (!vis[cur]) {
                    vis[cur] = true;
                    cur = b[cur] - 1;
                    len++;
                }

                int x = len;
                for (int p = 2; p * p <= x; p++) {
                    if (x % p == 0) {
                        int cnt = 0;
                        while (x % p == 0) {
                            x /= p;
                            cnt++;
                        }
                        mp[p] = max(mp[p], cnt);
                    }
                }
                if (x > 1)
                    mp[x] = max(mp[x], 1);
            }
        }

        long long ans = 1;
        for (auto &it : mp)
            ans = (ans * power(it.first, it.second)) % MOD;

        return (int)ans;
    }
};