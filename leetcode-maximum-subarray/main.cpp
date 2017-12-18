//https://leetcode.com/problems/maximum-subarray/description/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;

        int sum = nums[0];
        int ret = nums[0];
        for (int i=1; i<nums.size(); i++) {
            sum = max(nums[i], sum + nums[i]);
            ret = max(sum, ret);\
        }
        return ret;
    }
};

int main() {
    Solution s;
    vector<int> input = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << s.maxSubArray(input) << endl;
    return 0;
}