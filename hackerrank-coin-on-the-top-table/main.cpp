//https://www.hackerrank.com/challenges/coin-on-the-table/problem

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INFINITY = 3600;

vector<vector<char>> board;
int goalJ, goalI;
int n, m, k;

int solve() {
    int dp[k+1][n][m];

    for (int _k=0; _k<=k; _k++) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (i == 0 && j == 0) {
                    dp[_k][i][j] = 0;
                    continue;
                }

                dp[_k][i][j] = INFINITY;
                if (_k == 0)
                    continue;

                if (j-1 >= 0) {
                    dp[_k][i][j] = min(dp[_k][i][j], dp[_k-1][i][j-1] + (board[i][j-1] == 'R' ? 0 : 1));
                }

                if (j+1 < m) {
                    dp[_k][i][j] = min(dp[_k][i][j], dp[_k-1][i][j+1] + (board[i][j+1] == 'L' ? 0 : 1));
                }
                if (i-1 >= 0) {
                    dp[_k][i][j] = min(dp[_k][i][j], dp[_k-1][i-1][j] + (board[i-1][j] == 'D' ? 0 : 1));
                }
                if (i+1 < n) {
                    dp[_k][i][j] = min(dp[_k][i][j], dp[_k-1][i+1][j] + (board[i+1][j] == 'U' ? 0 : 1));
                }
            }
        }
    }

    int ret = INFINITY;
    for (int _k=0; _k<=k; _k++) {
        ret = min(ret, dp[_k][goalI][goalJ]);
    }

    return ret >= INFINITY ? -1 : ret;
}

int main() {
    cin >> n >> m >> k;

    board.assign(n, vector<char>(m));

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> board[i][j];
            if (board[i][j] == '*') {
                goalI = i;
                goalJ = j;
            }
        }
    }

    printf("%d\n", solve());

    return 0;
}