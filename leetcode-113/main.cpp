//https://leetcode.com/problems/path-sum-ii/description/
#include <iostream>
#include <vector>

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
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> append(int val, vector<int> v) {
    vector<int> appended;

    appended.push_back(val);

    for (auto& j : v) {
        appended.push_back(j);
    }

    return appended;
}

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector <vector <int>> ret;

        if (root == NULL)
            return ret;

        if (root->val == sum && !root->left && !root->right) {
            ret.resize(1);
            ret[0].push_back(root->val);
            return ret;
        }

        vector<vector<int>> left = pathSum(root->left, sum - root->val);
        vector<vector<int>> right = pathSum(root->right, sum - root->val);

        for (auto& i : left) {
            ret.push_back(append(root->val, i));
        }

        for (auto& i : right) {
            ret.push_back(append(root->val, i));
        }

        return ret;
    }
};


int main() {
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);

    n1.left = &n2;
    n1.right = &n3;

    Solution s;
    s.pathSum(&n1, 3);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}