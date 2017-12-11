//https://leetcode.com/problems/132-pattern/description/
#include <iostream>
#include <vector>
#include <stack>
#include <limits>

using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int s2 = numeric_limits<int>::min();
        stack<int> stack;

        for (int i=nums.size()-1; i>=0; i--) {
            if (nums[i] < s2)
                return true;

            while (!stack.empty() && stack.top() < nums[i]) {
                s2 = stack.top();
                stack.pop();
            }

            stack.push(nums[i]);
        }

        return false;
    }
};

int main() {
    Solution s;
    vector<int> input3 = {3, 5, 0, 3, 4};

//    cout << s.find132pattern(input0) << endl;
//    cout << s.find132pattern(input1) << endl;
//    cout << s.find132pattern(input2) << endl;
    if (s.find132pattern(input3))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}