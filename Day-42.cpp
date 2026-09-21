#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

/* Structure of binary tree Node
class Node {
    public:
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    bool areAnagrams(Node* root1, Node* root2) {
        if (!root1 && !root2) return true;
        if (!root1 || !root2) return false;

        queue<Node*> q1, q2;
        q1.push(root1);
        q2.push(root2);

        while (!q1.empty() && !q2.empty()) {
            int size1 = q1.size();
            int size2 = q2.size();

            // Both levels must have the same number of nodes
            if (size1 != size2) return false;

            unordered_map<int, int> freq;

            for (int i = 0; i < size1; ++i) {
                Node* curr1 = q1.front();
                q1.pop();
                freq[curr1->data]++;

                if (curr1->left) q1.push(curr1->left);
                if (curr1->right) q1.push(curr1->right);

                Node* curr2 = q2.front();
                q2.pop();
                freq[curr2->data]--;

                if (curr2->left) q2.push(curr2->left);
                if (curr2->right) q2.push(curr2->right);
            }

            // Verify frequencies match completely
            for (const auto& [val, count] : freq) {
                if (count != 0) {
                    return false;
                }
            }
        }

        return q1.empty() && q2.empty();
    }
};