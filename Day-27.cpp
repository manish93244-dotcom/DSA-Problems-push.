#include <vector>

using namespace std;

class Solution {
  public:
    bool isNegativeWeightCycle(int V, vector<vector<int>>& edges) {
        // Initialize distance array with 0 to handle disconnected components
        // (Equivalent to connecting a virtual super-source to all vertices with 0-weight edges)
        vector<int> dist(V, 0);

        // Relax all edges V - 1 times
        for (int i = 1; i <= V - 1; ++i) {
            for (const auto& edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];

                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }

        // Check for negative-weight cycles on the V-th relaxation pass
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            if (dist[u] + w < dist[v]) {
                return true;
            }
        }

        return false;
    }
};