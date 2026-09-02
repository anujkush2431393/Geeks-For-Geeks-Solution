class Solution {
  public:
    int solve(int n, string s) {
        int occupied = 0;
        int rejected = 0;

        bool inside[26] = {false};
        bool rejectedCustomer[26] = {false};

        for (char ch : s) {
            int id = ch - 'A';

            // First occurrence = arrival
            if (!inside[id] && !rejectedCustomer[id]) {
                if (occupied < n) {
                    inside[id] = true;
                    occupied++;
                } else {
                    rejectedCustomer[id] = true;
                    rejected++;
                }
            }
            // Second occurrence = departure
            else if (inside[id]) {
                inside[id] = false;
                occupied--;
            }
            // If rejectedCustomer[id] == true,
            // do nothing on departure
        }

        return rejected;
    }
};