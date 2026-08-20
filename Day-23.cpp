#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    int transform(string &s1, string &s2) {
        if (s1.length() != s2.length()) {
            return -1;
        }

        // Check if both strings are anagrams of each other
        unordered_map<char, int> freq;
        for (char c : s1) freq[c]++;
        for (char c : s2) freq[c]--;

        for (auto const& [key, count] : freq) {
            if (count != 0) {
                return -1;
            }
        }

        // Two-pointer approach from the end of both strings
        int i = s1.length() - 1;
        int j = s2.length() - 1;
        int operations = 0;

        while (i >= 0) {
            if (s1[i] == s2[j]) {
                j--;
            } else {
                operations++;
            }
            i--;
        }

        return operations;
    }
};