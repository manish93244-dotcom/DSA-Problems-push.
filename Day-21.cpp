#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  private:
    // Helper function to count triplets with sum <= target
    int countTripletsLessThanEqualTo(vector<int>& arr, int target) {
        int n = arr.size();
        int count = 0;

        for (int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                if (arr[i] + arr[left] + arr[right] <= target) {
                    // All pairs between left and right with current i have sum <= target
                    count += (right - left);
                    left++;
                } else {
                    right--;
                }
            }
        }

        return count;
    }

  public:
    int countTriplets(vector<int> &arr, int l, int r) {
        sort(arr.begin(), arr.end());

        // Triplets in [l, r] = (Triplets with sum <= r) - (Triplets with sum <= l - 1)
        return countTripletsLessThanEqualTo(arr, r) - countTripletsLessThanEqualTo(arr, l - 1);
    }
};