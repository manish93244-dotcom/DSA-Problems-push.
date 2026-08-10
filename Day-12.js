class Solution {
    maxTask(h, l) {
        const n = h.length;
        
        // Base case for empty arrays (though constraints say size >= 1)
        if (n === 0) return 0;
        
        // If there's only one day, just pick the maximum of high or low effort
        if (n === 1) return Math.max(h[0], l[0]);
        
        // prev2 represents dp[i-2], prev1 represents dp[i-1]
        let prev2 = 0; 
        let prev1 = Math.max(h[0], l[0]);
        
        for (let i = 1; i < n; i++) {
            // Choice 1: Low effort on current day + max tasks up to previous day
            const choiceLow = prev1 + l[i];
            
            // Choice 2: High effort on current day + max tasks up to two days ago
            const choiceHigh = prev2 + h[i];
            
            // Current max is the best of the two choices
            const current = Math.max(choiceLow, choiceHigh);
            
            // Shift our window forward for the next iteration
            prev2 = prev1;
            prev1 = current;
        }
        
        return prev1;
    }
}