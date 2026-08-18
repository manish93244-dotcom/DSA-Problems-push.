#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    // Double hashing to safely compare substrings in O(1)
    const long long MOD1 = 1000000007;
    const long long MOD2 = 1000000009;
    const long long BASE1 = 313;
    const long long BASE2 = 317;

public:
    string compress(string &s) {
        int n = s.length();
        if (n == 0) return "";

        vector<long long> h1(n + 1, 0), h2(n + 1, 0);
        vector<long long> p1(n + 1, 1), p2(n + 1, 1);

        for (int i = 0; i < n; i++) {
            h1[i + 1] = (h1[i] * BASE1 + s[i]) % MOD1;
            h2[i + 1] = (h2[i] * BASE2 + s[i]) % MOD2;
            p1[i + 1] = (p1[i] * BASE1) % MOD1;
            p2[i + 1] = (p2[i] * BASE2) % MOD2;
        }

        auto get_hash = [&](int l, int r) -> pair<long long, long long> {
            long long hash1 = (h1[r + 1] - h1[l] * p1[r - l + 1]) % MOD1;
            if (hash1 < 0) hash1 += MOD1;

            long long hash2 = (h2[r + 1] - h2[l] * p2[r - l + 1]) % MOD2;
            if (hash2 < 0) hash2 += MOD2;

            return {hash1, hash2};
        };

        string ans = "";
        int i = n;

        // Traverse backwards from length n to 1
        while (i > 0) {
            if (i % 2 == 0) {
                int half = i / 2;
                if (get_hash(0, half - 1) == get_hash(half, i - 1)) {
                    ans.push_back('*');
                    i = half;
                    continue;
                }
            }
            ans.push_back(s[i - 1]);
            i--;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};