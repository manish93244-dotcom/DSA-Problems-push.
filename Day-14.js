/**
 * @param {number[][]} grid
 * @return {number[]}
 */

class Solution {
    findWays(grid) {
        const n = grid.length;
        const MOD = 1e9 + 7;

        // Initialize 2D DP arrays for storing ways and max adventure
        const ways = Array.from({ length: n }, () => new Array(n).fill(0));
        const maxAdv = Array.from({ length: n }, () => new Array(n).fill(0));

        // Base case: Exit cell (n-1, n-1)
        ways[n - 1][n - 1] = 1;
        maxAdv[n - 1][n - 1] = grid[n - 1][n - 1];

        // Process grid in reverse order (from bottom-right to top-left)
        for (let i = n - 1; i >= 0; i--) {
            for (let j = n - 1; j >= 0; j--) {
                if (i === n - 1 && j === n - 1) continue;

                let totalWays = 0;
                let maxAdventureFromNext = -1;

                // Check Right move (allowed if cell value is 1 or 3)
                if ((grid[i][j] === 1 || grid[i][j] === 3) && j + 1 < n) {
                    if (ways[i][j + 1] > 0) {
                        totalWays = (totalWays + ways[i][j + 1]) % MOD;
                        maxAdventureFromNext = Math.max(maxAdventureFromNext, maxAdv[i][j + 1]);
                    }
                }

                // Check Down move (allowed if cell value is 2 or 3)
                if ((grid[i][j] === 2 || grid[i][j] === 3) && i + 1 < n) {
                    if (ways[i + 1][j] > 0) {
                        totalWays = (totalWays + ways[i + 1][j]) % MOD;
                        maxAdventureFromNext = Math.max(maxAdventureFromNext, maxAdv[i + 1][j]);
                    }
                }

                // If at least one valid path exists to the exit
                if (totalWays > 0) {
                    ways[i][j] = totalWays;
                    maxAdv[i][j] = grid[i][j] + maxAdventureFromNext;
                }
            }
        }

        // Return [totalPaths, maxAdventure] starting from (0, 0)
        return [ways[0][0], maxAdv[0][0]];
    }
}