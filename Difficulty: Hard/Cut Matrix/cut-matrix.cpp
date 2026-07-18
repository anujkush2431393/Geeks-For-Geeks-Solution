class Solution {
public:
    int findWays(vector<vector<int>>& matrix, int k) {
        const long long MOD = 1000000007;
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>> suffixRowSum(n, vector<int>(m+1,0));
        for(int r=0;r<n;r++)
            for(int c=m-1;c>=0;c--)
                suffixRowSum[r][c] = suffixRowSum[r][c+1] + matrix[r][c];
        
        vector<vector<int>> nextRow(n+1, vector<int>(m,0));
        for(int left=0; left<m; left++) nextRow[n][left] = n;
        for(int r=n-1;r>=0;r--)
            for(int left=0;left<m;left++)
                nextRow[r][left] = (suffixRowSum[r][left] > 0) ? r : nextRow[r+1][left];
        
        vector<vector<int>> suffixColSum(n+1, vector<int>(m,0));
        for(int c=0;c<m;c++)
            for(int top=n-1; top>=0; top--)
                suffixColSum[top][c] = suffixColSum[top+1][c] + matrix[top][c];
        
        vector<vector<int>> nextCol(n, vector<int>(m+1,0));
        for(int top=0; top<n; top++){
            nextCol[top][m] = m;
            for(int c=m-1;c>=0;c--)
                nextCol[top][c] = (suffixColSum[top][c] > 0) ? c : nextCol[top][c+1];
        }
        
        vector<vector<int>> S(n+1, vector<int>(m+1,0));
        for(int top=n-1; top>=0; top--)
            for(int left=m-1; left>=0; left--)
                S[top][left] = matrix[top][left] + S[top+1][left] + S[top][left+1] - S[top+1][left+1];
        
        vector<vector<long long>> cur(n, vector<long long>(m,0));
        cur[0][0]=1;
        
        for(int t=0;t<=k-2;t++){
            vector<vector<long long>> nxt(n, vector<long long>(m,0));
            for(int left=0; left<m; left++){
                vector<long long> diff(n,0);
                for(int top=0; top<n; top++){
                    long long val = cur[top][left];
                    if(val==0) continue;
                    int r = nextRow[top][left];
                    if(r < n){
                        int topStart = r+1;
                        if(topStart <= n-1)
                            diff[topStart] = (diff[topStart] + val) % MOD;
                    }
                }
                long long run=0;
                for(int topP=0; topP<n; topP++){
                    run = (run + diff[topP]) % MOD;
                    if(run!=0) nxt[topP][left] = (nxt[topP][left] + run) % MOD;
                }
            }
            for(int top=0; top<n; top++){
                vector<long long> diff(m,0);
                for(int left=0; left<m; left++){
                    long long val = cur[top][left];
                    if(val==0) continue;
                    int c = nextCol[top][left];
                    if(c < m){
                        int leftStart = c+1;
                        if(leftStart <= m-1)
                            diff[leftStart] = (diff[leftStart] + val) % MOD;
                    }
                }
                long long run=0;
                for(int leftP=0; leftP<m; leftP++){
                    run = (run + diff[leftP]) % MOD;
                    if(run!=0) nxt[top][leftP] = (nxt[top][leftP] + run) % MOD;
                }
            }
            cur = nxt;
        }
        
        long long ans=0;
        for(int top=0; top<n; top++)
            for(int left=0; left<m; left++)
                if(cur[top][left]!=0 && S[top][left] > 0)
                    ans = (ans + cur[top][left]) % MOD;
        
        return (int)ans;
    }
};