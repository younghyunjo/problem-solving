//https://leetcode.com/problems/hamming-distance/description/
#include <iostream>

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int ret =0;
        x = x ^ y;
        for (int i=0; i<32;i++) {
            ret += x &0x1;
            x = x >> 1;
        }
        return ret;
    }
};

int main() {
    Solution s;
    cout << s.hammingDistance(1, 1) << endl;
    return 0;
}