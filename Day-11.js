/**
 * @param {number[][]} mat
 * @return {number}
 */
class Solution {
    zigzagSequence(mat) {
        const n = mat.length;
        
        // Edge cases
        if (n === 0) return 0;
        if (n === 1) return mat[0][0];

        // dp array to store the max sum up to the previous row
        let prev = [...mat[0]];

        // Iterate starting from the second row
        for (let i = 1; i < n; i++) {
            let curr = new Array(n).fill(0);
            
            for (let j = 0; j < n; j++) {
                let maxPrev = 0;
                
                // Find the max value in the previous row from any column except j
                for (let k = 0; k < n; k++) {
                    if (j !== k) {
                        maxPrev = Math.max(maxPrev, prev[k]);
                    }
                }
                
                // Update current row's max sum for column j
                curr[j] = mat[i][j] + maxPrev;
            }
            
            // Move current row's results to prev for the next iteration
            prev = curr;
        }

        // The answer is the maximum value in the last processed row
        return Math.max(...prev);
    }
}