//https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> totalNumbers;
        for (int i=0; i<=nums.size(); i++)
            totalNumbers.push_back(i);

        for (auto i : nums) {
            totalNumbers[i] = 0;
        }

        vector<int> ret;
        for (auto i : totalNumbers) {
            if (i != 0)
                ret.push_back(i);
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