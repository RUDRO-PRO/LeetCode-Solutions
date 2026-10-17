/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <vector>
#include <stack>

class Solution {
public:
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> result;
        std::stack<TreeNode*> st;
        TreeNode* curr = root;

        while (curr != nullptr || !st.empty()) {
            // Reach the leftmost node of the current subtree
            while (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }

            // Current must be nullptr at this point, so pop from stack
            curr = st.top();
            st.pop();
            result.push_back(curr->val);

            // We have visited the node and its left subtree; now visit right
            curr = curr->right;
        }

        return result;
    }
};