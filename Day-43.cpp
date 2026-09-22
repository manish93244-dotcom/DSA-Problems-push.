#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
  private:
    bool isSubsequence(const string &word, const vector<vector<int>> &pos) {
        int last_idx = -1;
        for (char ch : word) {
            const vector<int> &indices = pos[ch - 'a'];
            auto it = upper_bound(indices.begin(), indices.end(), last_idx);
            if (it == indices.end()) {
                return false;
            }
            last_idx = *it;
        }
        return true;
    }

  public:
    string findLongestWord(string &s, vector<string> &d) {
        // Store indices of each character occurring in string s
        vector<vector<int>> pos(26);
        for (int i = 0; i < (int)s.size(); ++i) {
            pos[s[i] - 'a'].push_back(i);
        }

        string result = "";

        for (const string &word : d) {
            if (isSubsequence(word, pos)) {
                if (word.length() > result.length() || 
                   (word.length() == result.length() && word < result)) {
                    result = word;
                }
            }
        }

        return result;
    }
};