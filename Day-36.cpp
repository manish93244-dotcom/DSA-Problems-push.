#include <vector>
#include <algorithm>

using namespace std;

/* Binary Tree Node Structure
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  private:
    void getLeafLevels(Node* node, int level, vector<int>& leaf_costs) {
        if (node == nullptr) return;

        // Leaf node check
        if (node->left == nullptr && node->right == nullptr) {
            leaf_costs.push_back(level);
            return;
        }

        getLeafLevels(node->left, level + 1, leaf_costs);
        getLeafLevels(node->right, level + 1, leaf_costs);
    }

  public:
    int getCount(Node *root, int k) {
        if (root == nullptr || k <= 0) return 0;

        vector<int> leaf_costs;
        getLeafLevels(root, 1, leaf_costs);

        // Sort levels ascendingly to greedily pick the cheapest leaf nodes
        sort(leaf_costs.begin(), leaf_costs.end());

        int count = 0;
        for (int cost : leaf_costs) {
            if (k >= cost) {
                k -= cost;
                count++;
            } else {
                break;
            }
        }

        return count;
    }
};