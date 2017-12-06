#include <iostream>

using namespace std;

static char table[5][5];

bool hasWord(int x, int y, string s) {
    if (x < 0 || y < 0 || x >= 5 || y >= 5)
        return false;

    if (table[x][y] != s[0]) {
        return false;
    }

    s.erase(0, 1);
    if (s.empty())
        return true;

    int xStep[] = { -1, -1, -1, 0,  0, 1, 1,  1};
    int yStep[] = { -1,  0,  1, 1, -1, 0, 1, -1};

    for (int i=0; i<8; i++) {
        if (hasWord(x + xStep[i], y + yStep[i], s))
            return true;
    }

    return false;
}

bool _solve(string s) {
    for (int x=0; x<5; x++) {
        for (int y=0; y<5; y++) {
            if (hasWord(x, y, s))
                return true;
        }
    }
    return false;
}

void solve(void) {
    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++)
            scanf("%c", &table[i][j]);
        scanf("\n");
    }

    int n;
    scanf("%d\n", &n);

    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        if (_solve(s)) {
            cout << s << " YES" << endl;
        }
        else {
            cout << s << " NO" << endl;
        }

    }
}

int main() {
    int nrTestcase = 0;
    scanf("%d\n", &nrTestcase);

    for (int i=0; i<nrTestcase; i++) {
        solve();
    }

    return 0;
}