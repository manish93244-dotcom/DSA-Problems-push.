class Solution {
    countSubarray(arr, l, r) {
        // Helper function to count subarrays with sum <= target
        function countAtMost(target) {
            if (target < 0) return 0;
            
            let count = 0;
            let currentSum = 0;
            let left = 0;
            
            for (let right = 0; right < arr.length; right++) {
                currentSum += arr[right];
                
                while (currentSum > target && left <= right) {
                    currentSum -= arr[left];
                    left++;
                }
                
                count += (right - left + 1);
            }
            
            return count;
        }

        return countAtMost(r) - countAtMost(l - 1);
    }
}