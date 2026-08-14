class Solution {
public:
    bool isPossible(vector<int>& arr, int s, int x) {
        if (x == 0) return true;

        vector<long long> seq;
        long long sum = s;

        if (s <= x) seq.push_back(s);

        for (int val : arr) {
            if (sum > x) break;

            long long nxt = sum + val;

            if (nxt > x) break;

            seq.push_back(nxt);
            sum += nxt;
        }

        long long target = x;

        for (int i = seq.size() - 1; i >= 0; i--) {
            if (seq[i] <= target)
                target -= seq[i];
        }

        return target == 0;
    }
};