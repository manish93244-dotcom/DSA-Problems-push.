#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
  public:
    int formPyramid(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;

        // left[i] stores the max possible height of a pyramid peak if it increases up to index i
        vector<int> left(n, 0);
        left[0] = min(arr[0], 1);
        for (int i = 1; i < n; ++i) {
            left[i] = min({arr[i], left[i - 1] + 1, i + 1});
        }

        // right[i] stores the max possible height of a pyramid peak if it decreases from index i to the right
        vector<int> right(n, 0);
        right[n - 1] = min(arr[n - 1], 1);
        for (int i = n - 2; i >= 0; --i) {
            right[i] = min({arr[i], right[i + 1] + 1, n - i});
        }

        // Find the maximum peak height x possible across all indices
        long long max_peak = 0;
        for (int i = 0; i < n; ++i) {
            long long peak = min(left[i], right[i]);
            max_peak = max(max_peak, peak);
        }

        // Total initial height sum of all stones
        long long total_sum = 0;
        for (int x : arr) {
            total_sum += x;
        }

        // Sum of heights in a pyramid of peak x is x^2
        long long pyramid_sum = max_peak * max_peak;

        // Total cost required is the initial sum minus the pyramid sum
        return total_sum - pyramid_sum;
    }
};