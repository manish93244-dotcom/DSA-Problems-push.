class Solution {
public:
    int dominantPairs(vector<int> &arr) {
        int n = arr.size();
        
        // Sort the first half
        sort(arr.begin(), arr.begin() + n / 2);
        
        // Sort the second half
        sort(arr.begin() + n / 2, arr.end());
        
        int count = 0;
        int j = n / 2;
        
        // Iterate through the left half
        for (int i = 0; i < n / 2; ++i) {
            // Increment the right half pointer as long as the condition holds
            while (j < n && arr[i] >= 5 * arr[j]) {
                j++;
            }
            // All elements from n/2 up to j-1 are valid pairs for the current arr[i]
            count += (j - n / 2);
        }
        
        return count;
    }
};