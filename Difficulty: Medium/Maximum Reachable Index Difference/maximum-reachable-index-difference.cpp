class Solution {
  public:
    int maxIndexDifference(string &s) {
        int n = s.size();
        vector<int> maxReach(26, -1);
        int ans = -1;
        
        for (int i = n - 1; i >= 0; i--) {
            int c = s[i] - 'a';
            int reachVal;
            
            if (c == 25 || maxReach[c + 1] == -1) {
                reachVal = i;
            } else {
                reachVal = maxReach[c + 1];
            }
            
            if (reachVal > maxReach[c]) {
                maxReach[c] = reachVal;
            }
            
            if (c == 0) {
                ans = max(ans, reachVal - i);
            }
        }
        
        return ans;
    }
};