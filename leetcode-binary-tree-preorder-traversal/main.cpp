//https://leetcode.com/problems/binary-tree-preorder-traversal/description/

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
    void _preorderTraversal(TreeNode* node) {
        if (!node)
            return;

        ret.push_back(node->val);

        if (node->left)
            _preorderTraversal(node->left);
        if (node->right)
            _preorderTraversal(node->right);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        _preorderTraversal(root);
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
    vector<int> ret = s.preorderTraversal(&one);
    for(auto r : ret)
        cout << r << endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}