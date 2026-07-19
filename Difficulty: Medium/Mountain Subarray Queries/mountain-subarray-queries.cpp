class Solution {
  public:
    vector<bool> processQueries(vector<int> &arr, vector<vector<int>> &queries) {
        int n = arr.size();
        vector<int> incEnd(n), decEnd(n);
        incEnd[n - 1] = n - 1;
        decEnd[n - 1] = n - 1;
        
        // Right to left pass to compute farthest reach of 
        // non-decreasing / non-increasing runs starting at i
        for (int i = n - 2; i >= 0; i--) {
            incEnd[i] = (arr[i] <= arr[i + 1]) ? incEnd[i + 1] : i;
            decEnd[i] = (arr[i] >= arr[i + 1]) ? decEnd[i + 1] : i;
        }
        
        vector<bool> res;
        res.reserve(queries.size());
        
        for (auto &q : queries) {
            int l = q[0], r = q[1];
            
            // peak candidate: end of non-decreasing run starting at l,
            // clamped so it doesn't exceed r
            int k = min(incEnd[l], r);
            
            // from k, check if it stays non-increasing till r
            res.push_back(decEnd[k] >= r);
        }
        
        return res;
    }
};