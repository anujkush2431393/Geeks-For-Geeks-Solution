class Solution {
  public:
    int digitSum(int x) {
        int sum = 0;
        while (x > 0) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }

    int findMax(int n) {
        string s = to_string(n);
        int ans = n;
        int maxSum = digitSum(n);

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0')
                continue;

            string t = s;

            t[i]--;

            for (int j = i + 1; j < s.size(); j++)
                t[j] = '9';

            int x = stoi(t);
            int sum = digitSum(x);

            if (sum > maxSum || (sum == maxSum && x > ans)) {
                maxSum = sum;
                ans = x;
            }
        }

        return ans;
    }
};