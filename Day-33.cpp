#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int maxProduct(vector<int> &arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        long long prod = 1;

        // If k is equal to n, all elements must be included
        if (k == n) {
            for (int x : arr) prod *= x;
            return (int)prod;
        }

        // If k is odd and all numbers are negative, we must take the largest (least negative) numbers
        if (arr[n - 1] < 0 && (k % 2 == 1)) {
            for (int i = n - 1; i >= n - k; --i) {
                prod *= arr[i];
            }
            return (int)prod;
        }

        int left = 0;
        int right = n - 1;

        // If k is odd, take the largest positive number first
        if (k % 2 == 1) {
            prod *= arr[right];
            right--;
            k--;
        }

        // Pick elements in pairs from either end to maximize product
        while (k > 0) {
            long long left_pair = 1LL * arr[left] * arr[left + 1];
            long long right_pair = 1LL * arr[right] * arr[right - 1];

            if (left_pair > right_pair) {
                prod *= left_pair;
                left += 2;
            } else {
                prod *= right_pair;
                right -= 2;
            }
            k -= 2;
        }

        return (int)prod;
    }
};