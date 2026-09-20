#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int largestSubsquare(vector<vector<char>> &mat) {
        int n = mat.size();
        if (n == 0) return 0;

        // left[i][j]: consecutive 'X's to the left (including mat[i][j])
        // top[i][j]: consecutive 'X's moving upwards (including mat[i][j])
        vector<vector<int>> left(n, vector<int>(n, 0));
        vector<vector<int>> top(n, vector<int>(n, 0));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 'X') {
                    left[i][j] = (j == 0 ? 1 : left[i][j - 1] + 1);
                    top[i][j] = (i == 0 ? 1 : top[i - 1][j] + 1);
                }
            }
        }

        int max_side = 0;

        // Iterate through all possible bottom-right corners (i, j)
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                // The maximum side length achievable using bottom and right edges from (i, j)
                int k = min(left[i][j], top[i][j]);

                // Check if top and left edges of length k also exist
                while (k > max_side) {
                    if (top[i][j - k + 1] >= k && left[i - k + 1][j] >= k) {
                        max_side = k;
                        break;
                    }
                    k--;
                }
            }
        }

        return max_side;
    }
};