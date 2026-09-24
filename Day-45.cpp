#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int maxStackHeight(vector<int> &r, vector<int> &h) {
        int n = r.size();
        if (n == 0) return 0;

        // Group discs as (radius, height) pairs
        vector<pair<int, int>> discs(n);
        for (int i = 0; i < n; ++i) {
            discs[i] = {r[i], h[i]};
        }

        // Sort primarily by radius ascending, secondarily by height ascending
        sort(discs.begin(), discs.end());

        // Fenwick Tree (Binary Indexed Tree) for Coordinate Compression/Range Max Queries
        // Since h[i] <= 1000, we can directly index heights up to 1000.
        int max_h = 0;
        for (int height : h) {
            max_h = max(max_h, height);
        }

        vector<int> bit(max_h + 1, 0);

        auto update = [&](int idx, int val) {
            for (; idx <= max_h; idx += idx & -idx) {
                bit[idx] = max(bit[idx], val);
            }
        };

        auto query = [&](int idx) {
            int res = 0;
            for (; idx > 0; idx -= idx & -idx) {
                res = max(res, bit[idx]);
            }
            return res;
        };

        int overall_max_height = 0;

        // Group processing by distinct radius to strictly enforce r_top < r_bottom
        int i = 0;
        while (i < n) {
            int j = i;
            // Find all discs with the same radius
            while (j < n && discs[j].first == discs[i].first) {
                j++;
            }

            // Temporarily store the best heights for current radius group
            vector<pair<int, int>> updates;
            for (int k = i; k < j; ++k) {
                int height = discs[k].second;
                // Query maximum height achievable using a disc with strictly smaller height (height - 1)
                int best_prev = query(height - 1);
                int current_total = best_prev + height;
                updates.push_back({height, current_total});
                overall_max_height = max(overall_max_height, current_total);
            }

            // Update BIT after querying the whole group to maintain strict radius ordering
            for (const auto& u : updates) {
                update(u.first, u.second);
            }

            i = j;
        }

        return overall_max_height;
    }
};