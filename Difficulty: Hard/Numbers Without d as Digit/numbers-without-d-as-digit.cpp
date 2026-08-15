class Solution {
public:
    int countWithout(int n, int d) {
        if (n == 0) return 0;

        string s = to_string(n);
        int len = s.size();

        long long ans = 0;

        // Count numbers having fewer digits than n
        for (int digits = 1; digits < len; digits++) {
            long long firstChoices = (d == 0) ? 9 : 8;
            long long otherChoices = 9;

            ans += firstChoices * (long long)pow(otherChoices, digits - 1);
        }

        // Count numbers having same number of digits as n
        for (int i = 0; i < len; i++) {
            int cur = s[i] - '0';

            int smaller = 0;

            if (i == 0) {
                // First digit: 1 to cur-1
                for (int x = 1; x < cur; x++) {
                    if (x != d)
                        smaller++;
                }
            } else {
                // Other digits: 0 to cur-1
                for (int x = 0; x < cur; x++) {
                    if (x != d)
                        smaller++;
                }
            }

            ans += smaller * (long long)pow(9, len - i - 1);

            // Current digit is d, so n itself and
            // all larger continuations are invalid
            if (cur == d)
                return (int)ans;
        }

        // n itself does not contain d
        return (int)(ans + 1);
    }
};