//https://leetcode.com/problems/number-of-1-bits/description/

#include <iostream>
#include <stdint-gcc.h>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret = 0;
        for (int i=0; i<32; i++) {
            if (n & (1 << i))
                ret++;

        }
        return ret;
    }
};

int main() {

    Solution s;
    cout << s.hammingWeight(11) << endl;
    return 0;
}