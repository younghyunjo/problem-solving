//https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int lo = matrix[0][0];
        int hi = matrix[n-1][n-1];

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int count = getCount(matrix, mid);
            if (count < k) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return lo;
    }

private:
    int getCount(vector<vector<int>> matrix, int value) {
        int count = 0;
        int x = matrix.size() - 1;
        int y = 0;

        while (x >= 0 && y < matrix.size()) {
            if (matrix[x][y] <= value) {
                count += x + 1;
                y++;
            }
            else {
                x--;
            }
        }
        return count;
    }
};

int main() {
    vector<vector<int>> m1 {
            {1,5,9},
            {10, 11, 13},
            {12, 13, 15}
    };

    Solution s;
    cout << s.kthSmallest(m1, 1) << endl;
    return 0;
}