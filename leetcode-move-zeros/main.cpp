//https://leetcode.com/problems/move-zeroes/description/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=-1;

        for (int k=0; k<nums.size(); k++) {
            if (nums[k] != 0) {
                if (i != -1) {
                    nums[i++] = nums[k];
                    nums[k] = 0;
                }
            }
            else {
                if (i == -1) {
                    i = k;
                }
            }
        }
    }
};

int main() {
    vector<int> input = {0, 1, 0, 3, 12};
    vector<int> input2 = {2, 1};
    Solution s;
    s.moveZeroes(input2);

    for (auto i : input2)
        cout << i <<endl;

    return 0;
}