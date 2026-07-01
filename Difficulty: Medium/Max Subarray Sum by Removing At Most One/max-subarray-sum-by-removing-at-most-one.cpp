class Solution {
  public:
    int maxSumSubarray(vector<int>& arr) {
        int n = arr.size();
        
        long long fwd = arr[0];
        long long skip = LLONG_MIN; // can't skip when subarray has only 1 element
        long long ans = fwd;
        
        for (int i = 1; i < n; i++) {
            long long newSkip = max((long long)fwd, (skip == LLONG_MIN ? LLONG_MIN : skip + arr[i]));
            long long newFwd = max((long long)arr[i], fwd + arr[i]);
            
            fwd = newFwd;
            skip = newSkip;
            
            ans = max(ans, max(fwd, skip));
        }
        
        return (int)ans;
    }
};