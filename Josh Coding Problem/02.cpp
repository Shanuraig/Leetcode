#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* nearestRightNode(TreeNode* root, TreeNode* u) {
        // If the root or the node `u` is NULL, return NULL
        if (!root || !u) return nullptr;

        queue<TreeNode*> q;
        q.push(root);

        // Perform level-order traversal (BFS)
        while (!q.empty()) {
            int size = q.size();
            bool foundU = false;

            // Iterate over the current level
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                // If we find node `u`, the next node in the queue is the nearest right node
                if (foundU) {
                    return node; // Return the nearest right node
                }

                if (node == u) {
                    foundU = true; // Mark that we found `u`
                }

                // Add the child nodes to the queue
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }

        // If no nearest right node found, return nullptr
        return nullptr;
    }
};

int main() {
    // Example: Build a binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    TreeNode* u = root->left; // Node `u` is the subtree rooted at node with value 2

    Solution obj;
    TreeNode* rightNode = obj.nearestRightNode(root, u);

    if (rightNode) {
        cout << "Nearest right node of u is: " << rightNode->val << endl;
    } else {
        cout << "No nearest right node found." << endl;
    }

    return 0;
}
