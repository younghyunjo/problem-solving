//https://leetcode.com/problems/binary-tree-postorder-traversal/description/

#include <iostream>
#include <vector>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    vector<int> ret;
    void _postorderTraversal(TreeNode *node) {
        if (!node)
            return;

        if (node->left)
            _postorderTraversal(node->left);
        if (node->right)
            _postorderTraversal(node->right);

        ret.push_back(node->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode

        _postorderTraversal(root);
        return ret;
    }
};


int main() {
//    TreeNode root;

    TreeNode three(3);
    TreeNode two(2);
    TreeNode one(1);
    one.right = &two;
    two.left = &three;


    Solution s;
    vector<int> ret = s.postorderTraversal(&one);
    for(auto r : ret)
        cout << r << endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}