//https://leetcode.com/problems/maximum-subarray/description/

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class Solution {
private:
    vector<int> n;
    vector<int> dp;

    int _maxSubArray(int index) {
        if (index >= n.size())
                return 0;

        if (dp[index] != INT32_MIN)
            return dp[index];

        int s = n[index];
        dp[index] = max(s, _maxSubArray(index+1)+ s);
        return dp[index];
    }

public:
    int maxSubArray(vector<int>& nums) {
        n = nums;
        dp.assign(n.size(), INT32_MIN);
        int sum = numeric_limits<int>::min();

        for (int i=0; i<n.size(); i++) {
            sum = max(sum, _maxSubArray(i));
        }
        return sum;
    }
};

int main() {
    Solution s;
    vector<int> input = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << s.maxSubArray(input) << endl;
    return 0;
}