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
        if (!root) {
            return 0;
        }

        int depth = 0;
        queue<TreeNode*> s;
        s.push(root);

        while(!s.empty()) {
            depth++;
            int size = s.size();
            for (int i=0; i<size; i++) {
                TreeNode* n = s.front();
                s.pop();

                if (n->left)
                    s.push(n->left);
                if (n->right)
                    s.push(n->right);
            }
        }
        return depth;
    }
};

int main() {
    return 0;
}