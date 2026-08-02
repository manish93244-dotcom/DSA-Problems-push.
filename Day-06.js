/**
 * @param {number} n
 * @param {number} m
 * @return {number}
 */

class Solution {
    count(n, m) {
        // Precompute valid transitions for each value from 1 to m
        const validNext = Array.from({ length: m + 1 }, () => []);

        for (let i = 1; i <= m; i++) {
            for (let j = 1; j <= m; j++) {
                if (i % j === 0 || j % i === 0) {
                    validNext[i].push(j);
                }
            }
        }

        // dp[len][val] = number of valid arrays of length 'len' ending with 'val'
        let dp = new Array(m + 1).fill(1n); // Base case for length 1

        for (let len = 2; len <= n; len++) {
            const nextDp = new Array(m + 1).fill(0n);
            for (let current = 1; current <= m; current++) {
                for (const prev of validNext[current]) {
                    nextDp[current] += dp[prev];
                }
            }
            dp = nextDp;
        }

        // Sum up all valid arrays of length n
        let totalCount = 0n;
        for (let val = 1; val <= m; val++) {
            totalCount += dp[val];
        }

        return Number(totalCount);
    }
}