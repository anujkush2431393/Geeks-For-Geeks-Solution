class Solution {
  public:
    int minInsAndDel(vector<int> &a, vector<int> &b) {
        unordered_map<int, int> pos;
        
        for (int i = 0; i < b.size(); i++) {
            pos[b[i]] = i;
        }
        
        vector<int> seq;
        
        for (int x : a) {
            if (pos.count(x)) {
                seq.push_back(pos[x]);
            }
        }
        
        vector<int> lis;
        
        for (int x : seq) {
            auto it = lower_bound(lis.begin(), lis.end(), x);
            
            if (it == lis.end())
                lis.push_back(x);
            else
                *it = x;
        }
        
        int L = lis.size();
        
        return (a.size() - L) + (b.size() - L);
    }
};