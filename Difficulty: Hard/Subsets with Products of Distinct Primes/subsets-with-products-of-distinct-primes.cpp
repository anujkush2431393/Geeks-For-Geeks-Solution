class Solution {
public:
    const int MOD = 1e9 + 7;

    long long power(long long a, long long b, long long mod) {
        long long res = 1; a %= mod;
        while (b > 0) {
            if (b & 1) res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    }

    int countSubsets(vector<int> &arr) {
        vector<int> primes = {2,3,5,7,11,13,17,19,23,29};
        
        // count occurrences of each value
        unordered_map<int,int> cnt;
        long long onesCount = 0;
        for (int x : arr) {
            if (x == 1) { onesCount++; continue; }
            cnt[x]++;
        }
        
        int SZ = 1 << (int)primes.size(); // 1024
        vector<long long> dp(SZ, 0);
        dp[0] = 1;
        
        for (auto &[val, c] : cnt) {
            int mask = 0;
            int temp = val;
            bool squarefree = true;
            for (int i = 0; i < (int)primes.size(); i++) {
                int p = primes[i];
                if (temp % p == 0) {
                    int power_count = 0;
                    while (temp % p == 0) { temp /= p; power_count++; }
                    if (power_count > 1) { squarefree = false; break; }
                    mask |= (1 << i);
                }
            }
            if (temp != 1) squarefree = false; // shouldn't happen since val<=30 and all primes<=29 covered
            
            if (!squarefree || mask == 0) continue; // skip non-squarefree values (or val=1 handled separately)
            
            vector<long long> ndp = dp; // option: don't use this value
            for (int s = 0; s < SZ; s++) {
                if (dp[s] == 0) continue;
                if ((s & mask) == 0) {
                    int ns = s | mask;
                    ndp[ns] = (ndp[ns] + dp[s] * (long long)c) % MOD;
                }
            }
            dp = ndp;
        }
        
        long long sumNonEmpty = 0;
        for (int s = 1; s < SZ; s++) {
            sumNonEmpty = (sumNonEmpty + dp[s]) % MOD;
        }
        
        long long onesFactor = power(2, onesCount, MOD);
        long long ans = (sumNonEmpty * onesFactor) % MOD;
        
        return (int)ans;
    }
};