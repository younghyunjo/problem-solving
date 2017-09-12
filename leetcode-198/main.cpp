// https://leetcode.com/problems/house-robber/description/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        cache.assign(nums.size(), -1);
        n = nums;
        return _rob(0);
    }

private:
    vector<int> cache;
    vector<int> n;

    int _rob(int start) {
        if (start >= n.size())
            return 0;

        int& ret = cache[start];
        if (ret != -1)
            return ret;

        ret = max(n[start] + _rob(start + 2), _rob(start+1));

        return ret;
    }
};

int main() {
    Solution s;
    vector<int> num = {1, 10, 1, 1, 100};
    cout << s.rob(num) << endl;
    return 0;
}