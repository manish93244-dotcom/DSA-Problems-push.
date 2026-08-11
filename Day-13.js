/**
 * @param {number[][]} mat
 * @param {number[][]} queries
 * @param {number} k
 * @return {number[]}
 */
class Solution {
    largestSquare(mat, queries, k) {
        const n = mat.length;
        const m = mat[0].length;

        // Step 1: Build 2D Prefix Sum Array
        const pref = Array.from({ length: n + 1 }, () => new Array(m + 1).fill(0));
        for (let i = 0; i < n; i++) {
            for (let j = 0; j < m; j++) {
                pref[i + 1][j + 1] = mat[i][j] 
                                    + pref[i][j + 1] 
                                    + pref[i + 1][j] 
                                    - pref[i][j];
            }
        }

        // Helper function to get sum of elements in rectangle [r1, c1] to [r2, c2]
        const getSum = (r1, c1, r2, c2) => {
            return pref[r2 + 1][c2 + 1] - pref[r1][c2 + 1] - pref[r2 + 1][c1] + pref[r1][c1];
        };

        const result = [];

        // Step 2: Answer each query using binary search on radius 'r'
        for (const [r, c] of queries) {
            // First check if single cell centered at (r, c) is valid
            if (mat[r][c] > k) {
                result.push(-1);
                continue;
            }

            // Max possible expansion radius 'r_max' from (r, c) within matrix boundaries
            const maxRadius = Math.min(r, n - 1 - r, c, m - 1 - c);

            let low = 0;
            let high = maxRadius;
            let bestRadius = 0;

            while (low <= high) {
                const mid = Math.floor((low + high) / 2);
                const r1 = r - mid;
                const c1 = c - mid;
                const r2 = r + mid;
                const c2 = c + mid;

                const countOnes = getSum(r1, c1, r2, c2);

                if (countOnes <= k) {
                    bestRadius = mid;
                    low = mid + 1; // Try expanding further
                } else {
                    high = mid - 1; // Shrink search range
                }
            }

            // Side length of odd square centered at (r, c) is 2 * bestRadius + 1
            result.push(2 * bestRadius + 1);
        }

        return result;
    }
}