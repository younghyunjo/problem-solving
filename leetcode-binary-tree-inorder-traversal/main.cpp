//https://leetcode.com/problems/binary-tree-inorder-traversal/description/
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void doInorderTraveral(TreeNode* root, vector<int>& ret) {
        if (root->left)
            doInorderTraveral(root->left, ret);
        ret.push_back(root->val);
        if (root->right)
            doInorderTraveral(root->right, ret);
    }

public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;

        if (root == NULL)
            return ret;

        doInorderTraveral(root, ret);
        return ret;
    }
};

int main() {
    TreeNode N1(1);
    TreeNode N2(2);
    TreeNode N3(3);
    N1.right = &N2;
    N2.left = &N3;

    Solution s;
    vector<int> result = s.inorderTraversal(&N1);
    return 0;
}