#include <algorithm>
#include <climits>

using namespace std;

/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  private:
    int dfs(Node* node, int &max_diff) {
        if (node == nullptr) {
            return INT_MAX;
        }

        // A leaf node has no descendants to compare against
        if (node->left == nullptr && node->right == nullptr) {
            return node->data;
        }

        // Find the minimum value in left and right subtrees
        int leftMin = dfs(node->left, max_diff);
        int rightMin = dfs(node->right, max_diff);

        int minDescendant = min(leftMin, rightMin);

        // Update the maximum difference with the current node as ancestor
        max_diff = max(max_diff, node->data - minDescendant);

        // Return the minimum value in the entire subtree rooted at current node
        return min(node->data, minDescendant);
    }

  public:
    int maxDiff(Node* root) {
        int max_diff = INT_MIN;
        dfs(root, max_diff);
        return max_diff;
    }
};