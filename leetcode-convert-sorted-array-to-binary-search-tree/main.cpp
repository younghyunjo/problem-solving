//https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
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
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    TreeNode* _sortedArraytoBST(vector<int>& nums, int l, int r) {
        if (l > r)
            return NULL;
        int mid = (l+r) / 2;

        TreeNode* root = new TreeNode(nums[mid]);
        cout << root->val << endl;
        root->left = _sortedArraytoBST(nums, l, mid-1);
        root->right = _sortedArraytoBST(nums, mid+1, r);

        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return _sortedArraytoBST(nums, 0, nums.size()-1);
    }
};


int main() {
    vector<int> input = {-10, -3, 0, 5, 9};
    Solution s;
    s.sortedArrayToBST(input);
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}