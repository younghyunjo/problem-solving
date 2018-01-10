//https://leetcode.com/problems/path-sum/description/
#include <iostream>
#include <stack>

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
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL)
            return false;

        stack<pair<TreeNode*, int>> dfs;
        dfs.push(make_pair(root, sum));

        while (!dfs.empty()) {
            pair<TreeNode*, int> dNode = dfs.top();
            dfs.pop();

            TreeNode* n = dNode.first;
            int targetSum = dNode.second;

            if (n->left == NULL && n->right == NULL && n->val == targetSum)
                return true;
            else
            {
                if (n->left)
                    dfs.push(make_pair(n->left, targetSum - n->val));
                if (n->right)
                    dfs.push(make_pair(n->right, targetSum - n->val));
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);

    n1.left = &n2;
    n1.right = &n3;

    cout << s.hasPathSum(&n1, 13) << endl;
    return 0;

}