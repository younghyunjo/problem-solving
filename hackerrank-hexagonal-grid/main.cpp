//https://www.hackerrank.com/challenges/hexagonal-grid/problem

#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> grid;
vector<vector<int>> dp;
int n;

int isBlackened(int x, int y) {
    while (x < n && grid[0][x] == '1')
        x++;
    x =  min(x, n);

    while (y < n && grid[1][y] == '1')
        y++;

    y = min(y, n);

    if (x == n && y == n)
        return 1;

    int& ret = dp[x][y];
    if (ret != -1)
        return ret;

    if (x == y && y != n)
        ret = isBlackened(x+1, y+1);
    if (ret != 1 && x != n && x-1 == y )
        ret = isBlackened(x+1, y+1);
    if (ret != 1 && x+2 <= n && grid[0][x+1] != '1')
        ret = isBlackened(x+2, y);
    if (ret != 1&& y+2 <= n && grid[1][y+1] != '1')
        ret =  isBlackened(x, y+2);

    if (ret != 1)
        return 0 ;

    return ret;
}

string solve() {
    dp.assign(n+1, vector<int>(n+1, -1));

    int ret = isBlackened(0, 0);

    dp.clear();

    if (ret)
        return "YES";
    else
        return "NO";
}

int main() {
    int t;
    for (cin >> t; t; t--) {
        scanf("%d\n", &n);
        grid.assign(2, vector<char>(n, 0));
        for (int i=0; i<2; i++) {
            for (int j=0; j<n; j++) {
                scanf("%c", &grid[i][j]);
            }
            scanf("\n");
        }


        cout << solve() << endl;
        grid.clear();
    }
    return 0;
}