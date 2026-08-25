#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int minMoves(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;

        // dp[x] represents the length of the longest consecutive subsequence
        // of the form (k, k+1, k+2, ...) ending with value x
        vector<int> dp(n + 1, 0);
        int max_len = 0;

        for (int x : arr) {
            dp[x] = dp[x - 1] + 1;
            max_len = max(max_len, dp[x]);
        }

        // The minimum moves to sort the array is n - (longest consecutive increasing subsequence)
        return n - max_len;
    }
};