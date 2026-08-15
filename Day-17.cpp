 #include <string>
 #include <vector>
 #include <cstring>

 using namespace std;

 class Solution {
     int memo[12][2][2];
     string s;
     int target_d;

     int solve(int idx, bool tight, bool started) {
         if (idx == (int)s.length()) {
             return started ? 1 : 0;
         }

         if (memo[idx][tight][started] != -1) {
             return memo[idx][tight][started];
         }

         int limit = tight ? (s[idx] - '0') : 9;
         int ans = 0;

         for (int digit = 0; digit <= limit; digit++) {
             // Check if current digit equals 'd'
             if (digit == target_d) {
                 if (target_d == 0) {
                     // Cannot place 0 once the number has started (leading zeros are fine)
                     if (started) {
                         continue;
                     }
                 } else {
                     // Cannot place non-zero target digit 'd' at all
                     continue;
                 }
             }

             bool nextTight = tight && (digit == limit);
             bool nextStarted = started || (digit > 0);

             ans += solve(idx + 1, nextTight, nextStarted);
         }

         return memo[idx][tight][started] = ans;
     }

 public:
     int countWithout(int n, int d) {
         if (n <= 0) return 0;

         s = to_string(n);
         target_d = d;
         memset(memo, -1, sizeof(memo));

         return solve(0, true, false);
     }
 };