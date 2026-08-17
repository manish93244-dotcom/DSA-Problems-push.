#include <vector>
#include <queue>

using namespace std;

class Solution {
  public:
    int minThrows(int n, vector<int>& lad, vector<int>& sn) {
        int target = n * n;
        
        // 1-indexed board transition lookup
        vector<int> board(target + 1);
        for (int i = 1; i <= target; ++i) {
            board[i] = i;
        }

        // Apply ladders
        for (int i = 0; i < (int)lad.size(); i += 2) {
            board[lad[i]] = lad[i + 1];
        }

        // Apply snakes
        for (int i = 0; i < (int)sn.size(); i += 2) {
            board[sn[i]] = sn[i + 1];
        }

        vector<bool> visited(target + 1, false);
        queue<pair<int, int>> q;

        // Start at cell 1 with 0 throws
        q.push({1, 0});
        visited[1] = true;

        while (!q.empty()) {
            auto [curr, dist] = q.front();
            q.pop();

            if (curr == target) {
                return dist;
            }

            // Explore 6 possible dice rolls
            for (int dice = 1; dice <= 6; ++dice) {
                int nextCell = curr + dice;
                if (nextCell <= target) {
                    int finalCell = board[nextCell];

                    if (!visited[finalCell]) {
                        visited[finalCell] = true;
                        q.push({finalCell, dist + 1});
                    }
                }
            }
        }

        return -1;
    }
};