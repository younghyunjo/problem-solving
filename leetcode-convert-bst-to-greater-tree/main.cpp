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
private:
    int doConvertBTS(TreeNode* root, int sum) {
        if (!root)
            return sum;

        root->val += doConvertBTS(root->right, sum);
        return doConvertBTS(root->left, root->val);
    }

public:
    TreeNode* convertBST(TreeNode* root) {
        if (!root)
            return NULL;

        doConvertBTS(root, 0);

        return root;
    }
};

int main() {

    TreeNode n2(2);
    TreeNode n0(0);
    TreeNode n3(3);
    TreeNode n4(-4);
    TreeNode n1(1);

    n2.left = &n0;
    n2.right = &n3;
    n0.left = &n4;
    n0.right = &n1;

    Solution s;
    TreeNode* ret = s.convertBST(&n2);


    cout << ret->left->right->val << endl;



    return 0;
}