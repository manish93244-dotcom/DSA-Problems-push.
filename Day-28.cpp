#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    int countSubsequences(string& s, int n) {
        const int MOD = 1e9 + 7;
        
        // dp[r] stores the number of non-empty subsequences formed so far with value % n == r
        vector<int> dp(n, 0);

        for (char ch : s) {
            int digit = ch - '0';
            vector<int> next_dp = dp;

            // Option 1: Start a new single-digit subsequence with this digit
            int rem = digit % n;
            next_dp[rem] = (next_dp[rem] + 1) % MOD;

            // Option 2: Append this digit to all existing non-empty subsequences
            for (int r = 0; r < n; ++r) {
                if (dp[r] > 0) {
                    int new_rem = (r * 10 + digit) % n;
                    next_dp[new_rem] = (next_dp[new_rem] + dp[r]) % MOD;
                }
            }

            dp = move(next_dp);
        }

        return dp[0];
    }
};