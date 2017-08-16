#include <cstring>
#include <iostream>

int n;
int board[100][100];
int cache[100][100];

int jump(int y, int x) {
    if (x == n-1 && y == n-1)
        return 1;
    if (y>= n|| x >= n)
        return 0;

    int& ret = cache[y][x];
    if (ret != -1) {
        return ret;
    }

    int jumpSize = board[x][y];
    return ret = (jump(y + jumpSize, x) || jump(y, x + jumpSize));
}

void jumpgame() {
    std::cin >> n;

    memset(board, -1, sizeof(board));
    memset(cache, -1, sizeof(cache));

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            std::cin >> board[i][j];
        }
    }

    int ret = jump(0,0);

    if (ret) {
        std::cout << "YES" << std::endl;
    }
    else {
        std::cout << "NO" << std::endl;
    }
}

int main() {
    int nr_testcase;
    std::cin >> nr_testcase;

    for (int i=0; i<nr_testcase; i++) {
        jumpgame();
    }

    return 0;
}