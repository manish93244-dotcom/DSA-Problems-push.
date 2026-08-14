/**
 * @param {number[]} arr
 * @param {number} s
 * @param {number} x
 * @returns {boolean}
 */

class Solution {
    isPossible(arr, s, x) {
        if (x === 0) return true;

        const target = BigInt(x);
        const numbers = [];
        
        let currentS = BigInt(s);
        let runningSum = currentS;

        if (currentS <= target) {
            numbers.push(currentS);
        }

        // Generate the super-increasing sequence on the paper
        for (let i = 0; i < arr.length; i++) {
            const nextVal = runningSum + BigInt(arr[i]);
            
            if (nextVal <= target) {
                numbers.push(nextVal);
            }
            
            runningSum += nextVal;

            // Stop generating early if the next values clearly exceed target
            if (nextVal > target) {
                break;
            }
        }

        // Greedy choice from largest to smallest
        let rem = target;
        for (let i = numbers.length - 1; i >= 0; i--) {
            if (numbers[i] <= rem) {
                rem -= numbers[i];
            }
        }

        return rem === 0n;
    }
}