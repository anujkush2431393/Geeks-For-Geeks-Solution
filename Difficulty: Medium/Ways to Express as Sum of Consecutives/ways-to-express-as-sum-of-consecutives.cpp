class Solution {
  public:
    int getCount(int n) {
        int cnt = 0;
        
        for (int k = 2; k * (k + 1) / 2 <= n; k++) {
            int rem = n - (k * (k - 1)) / 2;
            
            if (rem > 0 && rem % k == 0)
                cnt++;
        }
        
        return cnt;
    }
};