//https://leetcode.com/problems/minimum-depth-of-binary-tree/description/
#include <iostream>
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
    int minDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        queue<pair<TreeNode*, int>> bfsQueue;
        bfsQueue.push(make_pair(root, 1));

        int depth = 0;
        while(!bfsQueue.empty()) {
            pair<TreeNode*, int> bfsNode = bfsQueue.front();
            bfsQueue.pop();
            TreeNode* node = bfsNode.first;
            depth = bfsNode.second;

            if (node->left == NULL && node->right == NULL) {
                break;
            }
            else {
                if (node->left) {
                    bfsQueue.push(make_pair(node->left, depth+1));
                }
                if (node->right) {
                    bfsQueue.push(make_pair(node->right, depth+1));
                }
            }
        }

        return depth;
    }
};

int main() {
    Solution s;
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);
    TreeNode n4(4);
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    cout << s.minDepth(&n1) << endl;
    return 0;
}