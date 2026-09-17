#include <vector>
#include <deque>

using namespace std;

class Solution {
  public:
    int minimumEdgeReversal(vector<vector<int>> &edges, int n, int src, int dst) {
        if (src == dst) return 0;

        // Build the graph:
        // Original edge u -> v with weight 0
        // Reversed edge v -> u with weight 1
        vector<vector<pair<int, int>>> adj(n + 1);
        for (const auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back({v, 0});
            adj[v].push_back({u, 1});
        }

        const int INF = 1e9;
        vector<int> dist(n + 1, INF);
        deque<int> dq;

        dist[src] = 0;
        dq.push_back(src);

        // 0-1 BFS
        while (!dq.empty()) {
            int u = dq.front();
            dq.pop_front();

            if (u == dst) {
                return dist[u];
            }

            for (const auto &[v, weight] : adj[u]) {
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    if (weight == 0) {
                        dq.push_front(v);
                    } else {
                        dq.push_back(v);
                    }
                }
            }
        }

        return dist[dst] == INF ? -1 : dist[dst];
    }
};