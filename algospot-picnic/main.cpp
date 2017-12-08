//https://algospot.com/judge/problem/read/PICNIC

#include <iostream>
#include <cstring>

using namespace std;

static int nrStudent;
static int nrPair;
static int p[10][10];


int solve(int taken[10]) {
    int first = -1;
    for (int i=0; i<nrStudent; i++) {
        if (taken[i] == 0) {
            first = i;
            break;
        }
    }

    if (first == -1)
        return 1;

    int ret = 0;
    for (int i=first+1; i<nrStudent; i++) {
        if (taken[i] == 0 && p[first][i] == 1) {
            taken[i] = 1;
            taken[first] = 1;
            ret += solve(taken);
            taken[i] = 0;
            taken[first] = 0;
        }
    }

    return ret;
}

int main() {
    int nrTestcase = 0;
    cin >> nrTestcase;

    while (nrTestcase--) {

        memset(p, 0, sizeof(p));

        cin >> nrStudent >> nrPair;
        for (int i=0; i<nrPair; i++) {
            int a, b;
            cin >> a >> b;

            p[a][b] = 1;
            p[b][a] = 1;
        }

        int taken[10];
        memset(taken, 0, sizeof(taken));
        cout << solve(taken) << endl;
    }

    return 0;
}