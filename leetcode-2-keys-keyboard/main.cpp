//https://leetcode.com/problems/2-keys-keyboard/description/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> dp;
    int n;
    int _minSteps(int written, int clipboard) {
        if (written == n)
            return 0;

        if (clipboard > n)
            return 1001;

        if (written > n)
            return 1001;

        int paste = _minSteps(written + clipboard, clipboard) + 1;
        int pasteAndCopy = _minSteps(written + clipboard, written + clipboard) + 2;

        return min(paste, pasteAndCopy);
    }

public:
    int minSteps(int nn) {
        if (nn == 1)
            return 0;

        n = nn;
        return _minSteps(1, 1) + 1;
    }
};

int main() {
    Solution s;
    cout <<  s.minSteps(6) << endl;

    return 0;
}