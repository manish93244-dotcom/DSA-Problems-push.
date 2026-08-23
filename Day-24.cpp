#include <vector>
#include <deque>

using namespace std;

class Solution {
  public:
    int numberOfCells(int r, int c, int u, int d, vector<vector<char>> &mat) {
        int n = mat.size();
        if (n == 0) return 0;
        int m = mat[0].size();

        // If start cell is out of bounds or an obstacle
        if (r < 0 || r >= n || c < 0 || c >= m || mat[r][c] == '#') {
            return 0;
        }

        const int INF = 1e9;
        // dist[i][j] stores the minimum up-moves required to reach (i, j)
        vector<vector<int>> dist(n, vector<int>(m, INF));
        deque<pair<int, int>> dq;

        dist[r][c] = 0;
        dq.push_back({r, c});

        // Direction vectors: Left, Right, Down, Up
        int dx[] = {0, 0, 1, -1};
        int dy[] = {-1, 1, 0, 0};
        int cost[] = {0, 0, 0, 1}; // Cost in terms of 'up' moves

        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();

            for (int k = 0; k < 4; ++k) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                int w = cost[k];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m && mat[nx][ny] != '#') {
                    if (dist[x][y] + w < dist[nx][ny]) {
                        dist[nx][ny] = dist[x][y] + w;
                        if (w == 0) {
                            dq.push_front({nx, ny});
                        } else {
                            dq.push_back({nx, ny});
                        }
                    }
                }
            }
        }

        int count = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] != '#' && dist[i][j] != INF) {
                    int up_moves = dist[i][j];
                    int down_moves = up_moves + (i - r);

                    if (up_moves <= u && down_moves <= d && down_moves >= 0) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};