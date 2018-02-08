#include <iostream>

using namespace std;

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
private::
    void doConvertBTS(TreeNode* root) {
        if (root->right) {
            doConvertBTS(root->right);
        }

        root->val =  root->val + root->right;

    }
public:
    TreeNode* convertBST(TreeNode* root) {
        if (!root)
            return NULL;



        return NULL;
    }
};

int main() {
    TreeNode n5(5);
    TreeNode n2(2);
    TreeNode n13(13);

    n5.left = &n2;
    n5.right = &n13;

    Solution s;
    s.convertBST(&n5);

    return 0;
}