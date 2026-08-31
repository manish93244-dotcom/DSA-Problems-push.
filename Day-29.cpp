#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    vector<int> getMarks(vector<int> &l, vector<int> &r, vector<int> &rank) {
        int n = l.size();
        
        // pref[i] stores the cumulative count of marks up to the i-th interval
        vector<long long> pref(n);
        for (int i = 0; i < n; ++i) {
            long long count = r[i] - l[i] + 1;
            pref[i] = count + (i > 0 ? pref[i - 1] : 0);
        }

        vector<int> ans;
        ans.reserve(rank.size());

        for (int k : rank) {
            // Find the interval containing the k-th mark using binary search
            int low = 0, high = n - 1;
            int idx = 0;

            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (pref[mid] >= k) {
                    idx = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            // Offset within the found interval
            long long prev_count = (idx > 0 ? pref[idx - 1] : 0);
            long long offset = k - prev_count - 1;

            ans.push_back(l[idx] + offset);
        }

        return ans;
    }
};