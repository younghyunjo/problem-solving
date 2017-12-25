//https://leetcode.com/problems/subarray-sum-equals-k/description/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {

public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSum;
        prefixSum[0] = 1;
        int sum = 0;
        int ret = 0;

        for (int i=0; i<nums.size(); i++) {
            sum += nums[i];
            ret += prefixSum[sum-k];
            prefixSum[sum]++;
        }

        return ret;
    }
};

int main() {
    vector<int> input = {1, 1, 1};
    Solution s;

    cout << s.subarraySum(input, 2) << endl;
    return 0;
}