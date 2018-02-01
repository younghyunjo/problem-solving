//https://leetcode.com/problems/move-zeroes/description/

#include <iostream>
#include <vector>

using namespace std;

static int x = [](){std::ios::sync_with_stdio(false);cin.tie(0);return 0;}();

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (!nums.size())
            return;

        int i=0;

        for (int k=0; k<nums.size(); k++) {
            if (nums[k])
                nums[i++] = nums[k];
        }

        for (; i<nums.size(); i++)
            nums[i] = 0;
    }
};

int main() {
    vector<int> input = {0, 1, 0, 3, 12};
    vector<int> input2 = {2, 1};
    Solution s;
    s.moveZeroes(input);

    for (auto i : input)
        cout << i <<endl;

    return 0;
}