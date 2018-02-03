//https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int len = nums.size();
        for (int i=0; i<len; i++) {
            int index = abs(nums[i]) -1;
            nums[index] = nums[index] > 0 ? -nums[index] : nums[index];
        }

        vector<int> ret;
        for (int i=0; i<len; i++) {
            if (nums[i] > 0) {
                ret.push_back(i+1);
            }
        }
        return ret;
    }
};

int main() {
    Solution s;

    vector<int> input = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> result = s.findDisappearedNumbers(input);
    for (auto i : result)
        cout << i << endl;
    return 0;
}