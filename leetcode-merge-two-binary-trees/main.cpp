//https://leetcode.com/problems/merge-two-binary-trees/description/
#include <iostream>

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
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL)
            return t2;
        if (t2 == NULL)
            return t1;
        else {
            t1->val += t2->val;
            t1->left = mergeTrees(t1->left, t2->left);
            t1->right = mergeTrees(t1->right, t2->right);
            return t1;
        }
    }
};

int main() {
    TreeNode Tl_1(1);
    TreeNode Tl_3(3);
    TreeNode Tl_2(2);
    TreeNode Tl_5(5);
    Tl_1.left = &Tl_3;
    Tl_1.right = &Tl_2;
    Tl_3.left = &Tl_5;

    TreeNode Tr_2(2);
    TreeNode Tr_1(1);
    TreeNode Tr_3(3);
    TreeNode Tr_4(4);
    TreeNode Tr_7(7);

    Tr_2.left = &Tr_1;
    Tr_2.right = &Tr_3;
    Tr_1.right = &Tr_4;
    Tr_3.right = &Tr_7;

    Solution s;
    s.mergeTrees(&Tl_1, &Tr_2);

    return 0;
}