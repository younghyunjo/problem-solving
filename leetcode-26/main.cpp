// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int i = 1;
        int j = 0;

        for (;i<nums.size(); i++) {
            if (nums[i] != nums[j]) {
                nums[++j] = nums[i];
            }
        }
        return j+1;
    }
};


int main() {
    Solution s;

    vector<int> nums = {0,1,2,2,3,4};
    cout << s.removeDuplicates(nums) << endl;

    return 0;
}