class Solution {
  public:
    vector<int> increasingNumbers(int n) {
        vector<int> result;
        
        if (n > 10) return result;
        
        // Use backtracking to generate all combinations
        // start: next digit to try (0-9)
        // current: number formed so far
        // count: digits placed so far
        
        function<void(int, int, int)> backtrack = [&](int start, int current, int count) {
            if (count == n) {
                // For n >= 2, leading digit 0 would make it (n-1) digit number
                // We handle this by checking: if n>=2, first digit must be >=1
                // But since we build digit by digit and check leading zero below, just add
                result.push_back(current);
                return;
            }
            
            for (int digit = start; digit <= 9; digit++) {
                // If it's the first digit and n > 1, skip 0 (leading zero)
                if (count == 0 && n > 1 && digit == 0) continue;
                
                backtrack(digit + 1, current * 10 + digit, count + 1);
            }
        };
        
        backtrack(0, 0, 0);
        
        return result;
    }
};