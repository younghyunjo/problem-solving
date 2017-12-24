//https://leetcode.com/problems/single-number-iii/description/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        if (nums.size() == 1)
            return nums;

        sort(nums.begin(), nums.end());

        vector<int> ret;
        int i;
        for (i=0; i<nums.size(); i++) {
            if (nums[i] != nums[i+1] || i == nums.size()-1)
                ret.push_back(nums[i]);
            else {
                int n = nums[i];
                while (n == nums[++i]);
                i -= 1;
            }
        }

        return ret;
    }
};

int main() {
    Solution s;
    vector<int> input = {-1, 0};
    vector<int> output = s.singleNumber(input);
    for (auto out : output)
        cout << out << endl;
    return 0;
}