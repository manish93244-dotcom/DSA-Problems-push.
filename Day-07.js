/**
 * @param {number[]} arr
 * @param {number} k
 * @returns {number}
 */
class Solution {
    countPairs(arr, k) {
        // Sort array in ascending order
        arr.sort((a, b) => a - b);

        let count = 0;
        let j = 0;
        const n = arr.length;

        for (let i = 0; i < n; i++) {
            // Move pointer j forward until the difference becomes >= k
            while (j < n && arr[j] - arr[i] < k) {
                j++;
            }
            // All elements between i + 1 and j - 1 form valid pairs with arr[i]
            count += (j - 1 - i);
        }

        return count;
    }
}