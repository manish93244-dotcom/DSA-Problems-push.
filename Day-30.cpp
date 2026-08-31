#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int minCost(int n, int i, int d, int c) {
        if (n <= 0) return 0;

        // dp[j] stores the minimum cost to form a string of length j
        vector<long long> dp(n + 1, 0);

        dp[1] = i;

        for (int j = 2; j <= n; ++j) {
            if (j % 2 == 0) {
                // If j is even: we can either add 1 character from (j - 1) or double (j / 2)
                dp[j] = min(dp[j - 1] + i, dp[j / 2] + c);
            } else {
                // If j is odd: we can either add 1 character from (j - 1) 
                // or double ((j + 1) / 2) and delete 1 character
                dp[j] = min(dp[j - 1] + i, dp[(j + 1) / 2] + c + d);
            }
        }

        return (int)dp[n];
    }
};