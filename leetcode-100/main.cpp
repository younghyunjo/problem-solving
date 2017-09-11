//https://leetcode.com/problems/same-tree/description/
#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> pStack;
        stack<TreeNode*> qStack;

        pStack.push(p);
        qStack.push(q);

        while (!pStack.empty() && !qStack.empty()) {
            TreeNode* pNode = pStack.top();
            pStack.pop();

            TreeNode* qNode = qStack.top();
            qStack.pop();

            if ((pNode && !qNode) || (!pNode && qNode)) {
                return false;
            }

            if (pNode && qNode) {
                if (pNode->val != qNode->val)
                    return false;
                pStack.push(pNode->left);
                pStack.push(pNode->right);
                qStack.push(qNode->left);
                qStack.push(qNode->right);
            }
        }

        if (pStack.empty() && qStack.empty())
            return true;

        return false;
    }
};


int main() {
    stack<TreeNode*> test;
    cout << test.empty() << endl;
    TreeNode N1(1);
    test.push(NULL);
    TreeNode* q = test.top();
    cout << test.empty() << endl;
    cout << q << endl;
    test.pop();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}