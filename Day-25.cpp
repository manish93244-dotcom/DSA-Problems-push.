#include <vector>

using namespace std;

class Solution {
  private:
    const long long MOD = 1000000007;

    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    long long modInverse(long long n) {
        return power(n, MOD - 2);
    }

  public:
    int prefixStrings(int n) {
        if (n <= 0) return 0;

        int total = 2 * n;
        vector<long long> fact(total + 1, 1);
        for (int i = 2; i <= total; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }

        // C_n = (2n)! / ((n + 1)! * n!) % MOD
        long long numerator = fact[2 * n];
        long long denominator = (fact[n + 1] * fact[n]) % MOD;

        long long ans = (numerator * modInverse(denominator)) % MOD;

        return ans;
    }
};