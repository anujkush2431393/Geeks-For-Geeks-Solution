class Solution {
  public:
    int shortestPath(int V, int src, int dest, vector<vector<int>> &edges) {
        int nodes = V;
        vector<vector<int>> adj(V + edges.size() + 5);

        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];

            if (w == 1) {
                adj[u].push_back(v);
                adj[v].push_back(u);
            } else {
                int x = nodes++;
                adj[u].push_back(x);
                adj[x].push_back(u);
                adj[x].push_back(v);
                adj[v].push_back(x);
            }
        }

        vector<int> dist(nodes, -1);
        queue<int> q;
        q.push(src);
        dist[src] = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }

        return dist[dest];
    }
};