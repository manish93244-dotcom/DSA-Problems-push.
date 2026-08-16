#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
  public:
    int minProd(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return arr[0];

        int neg_count = 0;
        int zero_count = 0;
        int max_neg = INT_MIN;
        int min_pos = INT_MAX;
        int prod = 1;

        for (int x : arr) {
            if (x == 0) {
                zero_count++;
                continue;
            }
            if (x < 0) {
                neg_count++;
                max_neg = max(max_neg, x);
            } else {
                min_pos = min(min_pos, x);
            }
            prod *= x;
        }

        // Case 1: No negative numbers
        if (neg_count == 0) {
            if (zero_count > 0) return 0;
            return min_pos;
        }

        // Case 2: Even count of negative numbers
        if (neg_count % 2 == 0) {
            // Remove the negative number closest to 0 to keep the product negative
            prod /= max_neg;
        }

        return prod;
    }
};