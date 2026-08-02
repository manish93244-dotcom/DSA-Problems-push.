class Solution {
    findMax(n, a, b, k) {
        let diff = new Array(n + 1).fill(0);
        let m = a.length;

       
        for (let i = 0; i < m; i++) {
            let start = a[i];
            let end = b[i];
            let val = k[i];

            diff[start] += val;
            if (end + 1 < n) {
                diff[end + 1] -= val;
            }
        }

        let maxVal = 0;
        let currentSum = 0;

        for (let i = 0; i < n; i++) {
            currentSum += diff[i];
            if (currentSum > maxVal) {
                maxVal = currentSum;
            }
        }

        return maxVal;
    }
}