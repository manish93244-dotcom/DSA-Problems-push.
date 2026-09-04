#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int maxFruits(vector<int>& arr, int m) {
        int n = arr.size();
        if (n == 0 || m <= 0) return 0;

        // If the bird can visit all trees or more
        if (m >= n) {
            long long total = 0;
            for (int x : arr) total += x;
            return (int)total;
        }

        // Sliding window of size m over a circular array
        long long current_sum = 0;
        for (int i = 0; i < m; ++i) {
            current_sum += arr[i];
        }

        long long max_sum = current_sum;

        // Slide the window around the circle
        for (int i = 1; i < n; ++i) {
            current_sum -= arr[i - 1];
            current_sum += arr[(i + m - 1) % n];
            max_sum = max(max_sum, current_sum);
        }

        return (int)max_sum;
    }
};