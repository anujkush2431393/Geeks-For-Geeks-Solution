class Solution {
  public:
    bool isNegativeWeightCycle(int V, vector<vector<int>>& edges) {

        // Initialize all distances to 0
        // This handles disconnected components as well.
        vector<int> dist(V, 0);

        // Relax all edges V times
        for (int i = 0; i < V; i++) {
            bool updated = false;

            for (auto &edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];

                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    updated = true;

                    // If relaxation happens on V-th iteration,
                    // negative weight cycle exists.
                    if (i == V - 1)
                        return true;
                }
            }

            // No update means no negative cycle
            if (!updated)
                break;
        }

        return false;
    }
};