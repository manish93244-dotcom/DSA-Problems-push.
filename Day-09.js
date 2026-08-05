class Solution {
    countMinOperations(arr) {
        let setBitsCount = 0;
        let maxVal = 0;

        for (let num of arr) {
            if (num > maxVal) {
                maxVal = num;
            }
            
            // Count set bits (number of +1 operations for this element)
            let temp = num;
            while (temp > 0) {
                if (temp & 1) {
                    setBitsCount++;
                }
                temp = temp >> 1;
            }
        }

        // Calculate the maximum number of double operations required
        let doubleOps = 0;
        while (maxVal > 1) {
            doubleOps++;
            maxVal = maxVal >> 1;
        }

        return setBitsCount + doubleOps;
    }
} 