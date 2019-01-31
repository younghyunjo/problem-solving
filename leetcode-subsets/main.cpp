//https://leetcode.com/problems/subsets/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> subset;
        doSubset(nums, 0, subset, subsets);
        return subsets;
    }


private:
    void doSubset(vector<int>& nums, int start, vector<int>subset, vector<vector<int>>& subsets) {
        subsets.push_back(subset);

        if (start >= nums.size())
            return;

        for (auto i=start; i<nums.size(); i++) {
            subset.push_back(nums[i]);
            doSubset(nums, i+1, subset, subsets);

            subset.pop_back();
        }
    }
};

int main() {
    vector<int> nums = {1, 2, 3};
    Solution s;
    auto subsets = s.subsets(nums);
    for (auto i : subsets) {
        for (auto j : i)
            std::cout << j << " ";
        std::cout << std::endl;
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}