class Solution {
  public:
    int maxAmount(vector<int>& arr, int k) {
        const int MOD = 1e9 + 7;
        
        priority_queue<int> pq;
        for (int x : arr)
            pq.push(x);
        
        long long ans = 0;
        
        while (k-- && !pq.empty()) {
            int cur = pq.top();
            pq.pop();
            
            ans = (ans + cur) % MOD;
            
            if (cur > 1)
                pq.push(cur - 1);
        }
        
        return ans % MOD;
    }
};