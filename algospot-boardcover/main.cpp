//https://algospot.com/judge/problem/read/BOARDCOVER

#include <iostream>
#include <cstring>

using namespace std;

int w, h;
int table[20][20];

int solve(void) {
    bool found = false;
    int x = -1, y = -1;
    for (y=0; y<h; y++) {
        for (x=0; x<w; x++) {
            if (table[y][x] == 0) {
                found = true;
                break;
            }
        }
        if (found)
            break;
    }

    if (!found)
        return 1;

    int ret = 0;

    for (int k=0; k<4; k++) {
        int x0, y0, x1, y1;
        switch (k) {
            case 0:
                x0 = x+1;
                y0 = y;
                x1 = x;
                y1 = y+1;
                break;
            case 1:
                x0 = x+1;
                y0 = y;
                x1 = x+1;
                y1 = y+1;
                break;
            case 2:
                x0 = x;
                y0 = y+1;
                x1 = x+1;
                y1 = y+1;
                break;
            case 3:
                x0 = x;
                y0 = y+1;
                x1 = x-1;
                y1 = y+1;
                break;
        }

        if (x0 < 0 || x1 < 0 || x0 >=w || x1 >=w)
            continue;
        if (y0 < 0 || y1 < 0 || y0 >=h || y1 >=h)
            continue;

        if (table[y0][x0] || table[y1][x1])
            continue;


        table[y0][x0] = 1;
        table[y][x] = 1;
        table[y1][x1] = 1;

        ret += solve();

        table[y0][x0] = 0;
        table[y][x] = 0;
        table[y1][x1] = 0;

    }

    return ret;
}

int main() {
    int nrTestcases;
    cin >> nrTestcases;

    while (nrTestcases--)
    {
        memset(table, 0, sizeof(table));

        cin >> h >> w;

        for (int y = 0; y < h; y++) {
            for (int x=0; x<w; x++) {
                char c;
                cin >> c;
                if (c == '#') {
                    table[y][x] = 1;
                }
                else if (c == '.') {
                    table[y][x] = 0;
                }
                else {
                    printf("ERR\n");
                }
            }
        }
        cout << solve() << endl;
    }
    return 0;
}