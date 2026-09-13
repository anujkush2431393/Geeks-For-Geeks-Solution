class Solution {
  public:
    pair<int, int> bfs(int src, vector<vector<int>> &adj) {
        int n = adj.size();
        vector<int> dist(n, -1);
        queue<int> q;

        dist[src] = 0;
        q.push(src);

        int farthest = src;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                v--;  // houses are 1-based

                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);

                    if (dist[v] > dist[farthest]) {
                        farthest = v;
                    }
                }
            }
        }

        return {farthest, dist[farthest]};
    }

    int partyHouse(vector<vector<int>> &adj) {
        // Find one endpoint of the diameter
        auto p1 = bfs(0, adj);

        // Find the diameter
        auto p2 = bfs(p1.first, adj);

        int diameter = p2.second;

        // Radius = ceil(diameter / 2)
        return (diameter + 1) / 2;
    }
};