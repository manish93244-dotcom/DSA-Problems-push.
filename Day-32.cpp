class Solution {
  public:
    int pairCount(int x, int y) {
        // LCM must be divisible by GCD
        if (y % x != 0) {
            return 0;
        }

        // Let a = x * p, b = x * q such that gcd(p, q) = 1 and p * q = y / x = k
        int k = y / x;
        int distinct_prime_factors = 0;

        // Count the number of distinct prime factors of k
        for (int d = 2; d * d <= k; ++d) {
            if (k % d == 0) {
                distinct_prime_factors++;
                while (k % d == 0) {
                    k /= d;
                }
            }
        }
        if (k > 1) {
            distinct_prime_factors++;
        }

        // Each distinct prime factor's full power can go to either p or q (2 choices each)
        return 1 << distinct_prime_factors;
    }
};