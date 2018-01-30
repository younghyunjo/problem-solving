//https://leetcode.com/problems/invert-binary-tree/description/

#include <iostream>
#include <queue>

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
    void swapChild(TreeNode* n) {
        TreeNode* left = n->left;
        n->left = n->right;
        n->right = left;
    }

public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root)
            return NULL;

        queue<TreeNode*> bfsQueue;

        bfsQueue.push(root);

        while(!bfsQueue.empty()) {
            TreeNode* n = bfsQueue.front();
            cout << n->val << endl;
            bfsQueue.pop();

            swapChild(n);
            if (n->left) {
                bfsQueue.push(n->left);
            }
            if (n->right) {
                bfsQueue.push(n->right);
            }
        }
        return root;
    }
};

int main() {
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);
    TreeNode n4(4);
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;

    Solution s;
    s.invertTree(&n1);

    return 0;
}