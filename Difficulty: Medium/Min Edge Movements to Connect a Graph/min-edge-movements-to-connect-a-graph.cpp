class Solution {
public:
    int minEdgesReq(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        
        // A connected graph with n vertices needs at least n-1 edges.
        if (m < n - 1)
            return -1;
        
        vector<vector<int>> adj(n);
        
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        vector<bool> vis(n, false);
        int components = 0;
        
        // Count connected components
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                components++;
                
                queue<int> q;
                q.push(i);
                vis[i] = true;
                
                while (!q.empty()) {
                    int u = q.front();
                    q.pop();
                    
                    for (int v : adj[u]) {
                        if (!vis[v]) {
                            vis[v] = true;
                            q.push(v);
                        }
                    }
                }
            }
        }
        
        // Each operation can connect at most two components.
        // So components - 1 operations are required.
        return components - 1;
    }
};