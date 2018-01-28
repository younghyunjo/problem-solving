//https://leetcode.com/problems/counting-bits/description/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret(num+1, 0);
        for (int i=1; i<=num; ++i) {
            ret[i] = ret[i&(i-1)] + 1;
        }
        return ret;

    }
};

int main() {
    Solution s;
    vector<int> ret = s.countBits(5);
    for (auto r : ret)
        cout << r << endl;
    return 0;
}