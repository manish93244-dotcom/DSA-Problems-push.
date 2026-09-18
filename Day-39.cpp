#include <algorithm>
#include <climits>

using namespace std;

/* Binary Tree Node Structure
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; 
*/

class Solution {
  private:
    void inorder(Node* root, Node* &prev, int &min_diff) {
        if (root == nullptr) return;

        inorder(root->left, prev, min_diff);

        if (prev != nullptr) {
            min_diff = min(min_diff, root->data - prev->data);
        }
        prev = root;

        inorder(root->right, prev, min_diff);
    }

  public:
    int absDiff(Node *root) {
        int min_diff = INT_MAX;
        Node* prev = nullptr;
        inorder(root, prev, min_diff);
        return min_diff;
    }
};