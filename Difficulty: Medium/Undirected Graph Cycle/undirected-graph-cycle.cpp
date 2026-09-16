class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> visited(V, 0);

        for (int i = 0; i < V; i++) {
            if (visited[i] == 0) {
                if (dfs(i, visited, adj, -1)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(int s, vector<int>& visited, vector<vector<int>>& adj, int p) {
        visited[s] = 1;

        for (int i = 0; i < adj[s].size(); i++) {
            int neighbor = adj[s][i];
            if (visited[neighbor] == 0) {
                if (dfs(neighbor, visited, adj, s)) {
                    return true;
                }
            } 
            else if (neighbor != p) {
                return true;
            }
        }
        return false;
    }
};