// https://leetcode.com/problems/n-queens/
#include <iostream>
#include <vector>
#include <limits>
#include <numeric>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        n_ = n;
        chessboard_ = vector<string>(n, std::string(n, '.'));

        solve(0);

        return ret;
    }

private:
    bool solve(int row) {
        if (row == n_) {
            ret.push_back(chessboard_);
            return true;
        }

        for (auto c=0; c<n_; c++) {
            if (isValid(row, c)) {
                continue;
            }
            chessboard_[row][c] = 'Q';
            solve(row+1);
            chessboard_[row][c] = '0';

        }

        return false;
    }

    bool isValid(int row, int col) {
        //column has queen
        for (auto r=0; r<n_; r++) {
            if (chessboard_[r][col] == 'Q')
                return true;
        }

        //45 diagonal
        for (auto r=row-1, c=col+1; r>=0 && c<n_; r--, c++) {
            if (chessboard_[r][c] == 'Q')
                return true;
        }

        //135 diagonal
        for (auto r=row-1, c=col-1; r>=0 && c>=0; r--, c--) {
            if (chessboard_[r][c] == 'Q')
                return true;
        }
        return false;
    }

    int n_ = 0;
    vector<string> chessboard_;
    vector<vector<string>> ret;
};

int main() {
    Solution s;
    s.solveNQueens(4);

    return 0;
}
