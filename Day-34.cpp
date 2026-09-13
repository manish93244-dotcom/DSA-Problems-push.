#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
  private:
    // Helper function to find the farthest node and its distance from a start node using BFS
    pair<int, int> bfs(int startNode, int n, const vector<vector<int>> &adj) {
        vector<int> dist(n + 1, -1);
        queue<int> q;

        dist[startNode] = 0;
        q.push(startNode);

        int farthestNode = startNode;
        int maxDist = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            if (dist[u] > maxDist) {
                maxDist = dist[u];
                farthestNode = u;
            }

            // adj is 0-indexed corresponding to house (u)
            for (int v : adj[u - 1]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }

        return {farthestNode, maxDist};
    }

  public:
    int partyHouse(vector<vector<int>> &adj) {
        int n = adj.size();
        if (n <= 1) return 0;

        // 1. Find one endpoint of the tree's diameter
        auto [nodeA, distA] = bfs(1, n, adj);

        // 2. Find the other endpoint and the diameter (D)
        auto [nodeB, diameter] = bfs(nodeA, n, adj);

        // The minimum possible maximum distance to any house is the tree radius: ceil(diameter / 2)
        return (diameter + 1) / 2;
    }
};