//https://leetcode.com/problems/largest-number/description/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string &s1, string &s2) {
    return s1 + s2 > s2 + s1;
}

class Solution {
private:

public:
    string largestNumber(vector<int>& nums) {
        vector<string> stringNums;
        for (auto n : nums)
            stringNums.push_back(to_string(n));
        sort(stringNums.begin(), stringNums.end(), compare);

        string ret = "";
        for (auto s : stringNums)
            ret += s;

        if (ret[0] == '0' && ret[1] == '0')
            return "0";

        return ret;
    }
};

int main() {
    vector<int> input = {3, 30, 34, 5, 9, 0};
    vector<int> input1 = {0, 0, 0};

    Solution s;
    cout << s.largestNumber(input) << endl;
    cout << s.largestNumber(input1) << endl;
    return 0;
}