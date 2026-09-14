#include <vector>
#include <queue>

using namespace std;

class Solution {
  public:
    int shortestPath(vector<vector<int>> &mat) {
        int n = mat.size();
        if (n == 0) return -1;
        int m = mat[0].size();

        // safe[i][j] will mark whether cell (i, j) is safe to step on
        vector<vector<bool>> safe(n, vector<bool>(m, true));

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        // Mark all landmines and their 4-directionally adjacent cells as unsafe
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == 0) {
                    safe[i][j] = false;
                    for (int k = 0; k < 4; ++k) {
                        int ni = i + dx[k];
                        int nj = j + dy[k];
                        if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                            safe[ni][nj] = false;
                        }
                    }
                }
            }
        }

        // BFS initialization
        queue<pair<int, int>> q;
        vector<vector<int>> dist(n, vector<int>(m, -1));

        // Push all safe cells in the leftmost column (col = 0)
        for (int i = 0; i < n; ++i) {
            if (safe[i][0]) {
                q.push({i, 0});
                dist[i][0] = 1; // Length of path counting cells visited
                if (m == 1) return 1;
            }
        }

        // Multi-source BFS
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            // Check if we reached the rightmost column
            if (y == m - 1) {
                return dist[x][y];
            }

            for (int k = 0; k < 4; ++k) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m && safe[nx][ny] && dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    if (ny == m - 1) {
                        return dist[nx][ny];
                    }
                    q.push({nx, ny});
                }
            }
        }

        return -1;
    }
};