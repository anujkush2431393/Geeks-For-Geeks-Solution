class Solution {
  public:
    int minThrows(int n, vector<int>& lad, vector<int>& sn) {
        int N = n * n;

        // next[i] = destination if there is a snake/ladder at i
        vector<int> next(N + 1, -1);

        for (int i = 0; i < lad.size(); i += 2) {
            next[lad[i]] = lad[i + 1];
        }

        for (int i = 0; i < sn.size(); i += 2) {
            next[sn[i]] = sn[i + 1];
        }

        // BFS
        vector<int> dist(N + 1, -1);
        queue<int> q;

        q.push(1);
        dist[1] = 0;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            if (curr == N)
                return dist[curr];

            // Try dice values 1 to 6
            for (int dice = 1; dice <= 6; dice++) {
                int nextCell = curr + dice;

                if (nextCell > N)
                    break;

                // Take snake or ladder if present
                if (next[nextCell] != -1)
                    nextCell = next[nextCell];

                // Visit only unvisited cells
                if (dist[nextCell] == -1) {
                    dist[nextCell] = dist[curr] + 1;
                    q.push(nextCell);
                }
            }
        }

        return -1;
    }
};