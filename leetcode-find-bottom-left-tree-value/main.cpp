//https://leetcode.com/problems/find-bottom-left-tree-value/description/

#include <iostream>
#include <algorithm>
#include <queue>

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
public:
    int findBottomLeftValue(TreeNode* root) {
        return bfs(root);
    }

private:
    int bfs(TreeNode* root) {
        int ret = -1;
        queue<TreeNode*> bfsQueue;
        bfsQueue.push(root);

        while(!bfsQueue.empty()) {
            TreeNode* node = bfsQueue.front();
            bfsQueue.pop();
            ret = node->val;
            if (node->right)
                bfsQueue.push(node->right);
            if (node->left)
                bfsQueue.push(node->left);
        }

        return ret;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}