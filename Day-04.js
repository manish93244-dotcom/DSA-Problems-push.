/**
 * @param {number[]} arr
 * @return {number}
 */
class Solution {
    countSubsets(arr) {
        const MOD = 1000000007n;
        const PRIMES = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29];

        // Helper function to get prime bitmask for a number
        const getPrimeMask = (val) => {
            let mask = 0;
            for (let i = 0; i < PRIMES.length; i++) {
                const prime = PRIMES[i];
                let count = 0;
                while (val % prime === 0) {
                    count++;
                    val = Math.floor(val / prime);
                }
                if (count > 1) return -1; // Not square-free
                if (count === 1) {
                    mask |= (1 << i);
                }
            }
            return mask;
        };

        // Helper function for modular exponentiation with BigInt
        const power = (base, exp) => {
            let res = 1n;
            base = BigInt(base) % MOD;
            exp = BigInt(exp);
            while (exp > 0n) {
                if (exp % 2n === 1n) res = (res * base) % MOD;
                base = (base * base) % MOD;
                exp /= 2n;
            }
            return res;
        };

        const freq = new Array(31).fill(0);
        for (const x of arr) {
            freq[x]++;
        }

        // dp[mask] = count of subsets with prime factor mask
        const dp = new Array(1 << 10).fill(0n);
        dp[0] = 1n; // Base case: empty set

        // Process numbers from 2 to 30
        for (let i = 2; i <= 30; i++) {
            if (freq[i] === 0) continue;

            const mask = getPrimeMask(i);
            if (mask === -1) continue; // Skip non-square-free numbers

            const countBig = BigInt(freq[i]);

            // Iterate backwards to update DP state safely
            for (let currentMask = (1 << 10) - 1; currentMask >= 0; currentMask--) {
                if ((currentMask & mask) === 0) { // Disjoint prime factors
                    dp[currentMask | mask] = (dp[currentMask | mask] + dp[currentMask] * countBig) % MOD;
                }
            }
        }

        // Sum up total valid non-empty prime-product subsets (excluding mask 0)
        let totalValidWithoutOnes = 0n;
        for (let mask = 1; mask < (1 << 10); mask++) {
            totalValidWithoutOnes = (totalValidWithoutOnes + dp[mask]) % MOD;
        }

        // Each valid subset containing at least one prime can freely include or exclude any of the 1s
        const powerOfTwoForOnes = power(2n, freq[1]);
        const result = (totalValidWithoutOnes * powerOfTwoForOnes) % MOD;

        return Number(result);
    }
}