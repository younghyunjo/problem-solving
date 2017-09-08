// https://leetcode.com/problems/unique-paths/description/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        _m = m;
        _n = n;
        cache.assign(m, vector<int>(n, -1));
        return _uniquePaths(0, 0);
    }

private:
    int _uniquePaths(int x, int y) {
        if (x >= _n)
            return 0;
        if (y >= _m)
            return 0;

        int& ret = cache[y][x];
        if (ret != -1)
            return ret;

        if (x == _n-1 && y == _m-1)
            return 1;

        ret = _uniquePaths(x+1, y) + _uniquePaths(x, y+1) ;
        return ret;
    }

    vector<vector<int>> cache;
    int _m;
    int _n;
};

int main() {
    Solution s;
    cout << s.uniquePaths(3, 2) << endl;
    return 0;
}