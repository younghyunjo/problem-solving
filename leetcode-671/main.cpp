//https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/description/

#include <iostream>
#include <stack>
#include <limits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        int smallest = root->val;
        int secondSmallest = numeric_limits<int>::max();
        stack<TreeNode*> dfsStack;

        dfsStack.push(root);
        while(!dfsStack.empty()) {
            TreeNode* n = dfsStack.top();
            dfsStack.pop();

            if (n->val != smallest && n->val < secondSmallest)
                secondSmallest = n->val;

            if (n->left && n->left->val < secondSmallest)
                dfsStack.push(n->left);

            if (n->right && n->right->val < secondSmallest)
                dfsStack.push(n->right);
        }

        if (smallest == secondSmallest || secondSmallest == numeric_limits<int>::max())
            return -1;

        return secondSmallest;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}