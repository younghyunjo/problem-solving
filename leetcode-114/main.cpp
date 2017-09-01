//https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/

#include <iostream>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == NULL)
            return;

        if (root->right == NULL && root->left == NULL)
            return;

        if (root->right) {
            flatten(root->right);
        }

        if (root->left) {
            flatten(root->left);
        }

        if (root->right && root->left) {
            TreeNode *lastRightFromLeftNode = root->left;
            while (lastRightFromLeftNode->right) {
                lastRightFromLeftNode = lastRightFromLeftNode->right;
            }
            lastRightFromLeftNode->right = root->right;
        }

        if (root->left) {
            root->right = root->left;
            root->left = NULL;
        }
    }
};

int main() {

    Solution s;
    TreeNode N1(1);
    TreeNode N2(2);
    TreeNode N3(3);
    TreeNode N4(4);
    TreeNode N5(5);
    TreeNode N6(6);

    N1.right = &N2;

    s.flatten(&N1);

    return 0;
}
