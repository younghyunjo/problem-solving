//https://leetcode.com/problems/binary-tree-tilt/description/

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    int findTilt(TreeNode* root) {
        sum(root);
        return ret;
    }
private:
    int ret = 0;
    int sum(TreeNode* root) {
        if (root == NULL)
            return 0;

        int sumRight = sum(root->right);
        int sumLeft = sum(root->left);

        ret += abs(sumRight - sumLeft);
        return sumRight + sumLeft + root->val;
    }
};

int main() {
    TreeNode N1(1);
    TreeNode N2(2);
    TreeNode N3(3);
    N1.left = &N2;
    N1.right = &N3;

    Solution s;
    cout << s.findTilt(&N1);
    return 0;
}