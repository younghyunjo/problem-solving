//https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;

        int depth = 0;
        int qIndex = 0;
        int next = 1;
        queue<TreeNode*> q[2];

        q[qIndex].push(root);

        TreeNode* n;
        while (!q[qIndex].empty()) {
            n = q[qIndex].front();
            q[qIndex].pop();

            if (n->left)
                q[next].push(n->left);
            if (n->right)
                q[next].push(n->right);

            if (q[qIndex].empty()) {
                depth++;
                next = (next+1) % 2;
                qIndex = (qIndex+1) % 2;
            }
        }
        return depth;
    }
};

int main() {
    return 0;
}