
import java.util.*;

class Solution {

    int insertAmt, deleteAmt, copyAmt;
    int[] dp;

    public int minCost(int n, int i, int d, int c) {

        insertAmt = i;
        deleteAmt = d;
        copyAmt = c;

        dp = new int[n + 1];
        Arrays.fill(dp, -1);

        return solve(n);
    }

    int solve(int len) {

        // If no characters are required
        if (len == 0)
            return 0;

        // To create one character, only insertion is possible
        if (len == 1)
            return insertAmt;

        // Already calculated
        if (dp[len] != -1)
            return dp[len];

        // Option 1:
        // Create all characters using insertion
        int ans = len * insertAmt;

        if (len % 2 == 0) {

            // len -> len/2
            // Reverse of copy-paste
            int copy = copyAmt + solve(len / 2);

            ans = Math.min(ans, copy);

        } else {

            // Option 2:
            // len -> len-1
            // Reverse of insertion
            int down = insertAmt + solve(len - 1);

            // Option 3:
            // len -> len+1 using reverse of deletion
            // len+1 -> (len+1)/2 using reverse of copy-paste
            int up = deleteAmt
                    + copyAmt
                    + solve((len + 1) / 2);

            ans = Math.min(ans, Math.min(down, up));
        }

        return dp[len] = ans;
    }
}
