class Solution {
  public:
    bool solve(int i,int j,vector<vector<int>>& mat,vector<vector<int>>&ans,vector<vector<int>>&dp){
        //base case
        int n=mat[0].size();
         if(i==n-1 && j==n-1){
            ans[n-1][n-1]=1;
            return true;
        } 
        if(i>=n || j>=n || mat[i][j]==0) return false;
        
        //recursive case
        if(dp[i][j] != -1) return dp[i][j];
        ans[i][j]=1;
        int steps = mat[i][j];
        for(int k =1;k<=steps;k++){
            if (solve(i,j+k,mat,ans,dp)) return dp[i][j]=1;
            if (solve(i+k,j,mat,ans,dp)) return dp[i][j]=1;
        }
        ans[i][j]=0;
        return dp[i][j]=0;
    }
    vector<vector<int>> shortestDist(vector<vector<int>>& mat) {
        // CodeGenius
        int n= mat[0].size();
        vector<vector<int>>ans(n,vector<int>(n,0));
        vector<vector<int>>dp(n,vector<int>(n,-1));
        if(!solve(0,0,mat,ans,dp)) return {{-1}};
        return ans;
        
    }
};