//https://leetcode.com/problems/n-queens-ii/description/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int totalNQueens(int N) {
        board.assign(N+1, 0);
        n = N;
        _nQueens(0);
        return ret;
    }

private:
    void _nQueens(int i) {
        if (_isPossibleToPutQueen(i)) {
            if (i == n) {
                ret++;
                return;
            }

            for(int j=1; j<=n; j++) {
                board[i+1] = j;
                _nQueens(i+1);
            }
        }
    }

    bool _isPossibleToPutQueen(int i) {
        int j=1;
        while (j<i) {
            if (board[i] == board[j] || abs(board[i] - board[j]) == abs(i-j))
                return false;
            j++;
        }

        return true;
    }

    int ret = 0;
    int n;
    vector<int> board;
};

int main() {
    Solution s;
    cout << s.totalNQueens(10) << endl;
    return 0;
}