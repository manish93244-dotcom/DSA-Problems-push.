#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int findMinCost(string &s1, string &s2, int costS1, int costS2) {
        int n = s1.size();
        int m = s2.size();

        // dp[i][j] stores the length of LCS for prefixes s1[0...i-1] and s2[0...j-1]
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        int lcs_len = dp[n][m];

        // Total cost = (deletions in s1 * costS1) + (deletions in s2 * costS2)
        int deletions_s1 = n - lcs_len;
        int deletions_s2 = m - lcs_len;

        return deletions_s1 * costS1 + deletions_s2 * costS2;
    }
};