#include <iostream>
#include <cstring>
#include <vector>
#include <limits>

using namespace std;

#define CLOCKS      16
#define SWITCHES    10

const int INF = 9999;



const char linked[SWITCHES][CLOCKS+1] = {
        "xxx.............",
        "...x...x.x.x....",
        "....x.....x...xx",
        "x...xxxx........",
        "......xxx.x.x...",
        "x.x...........xx",
        "...x..........xx",
        "....xx.x......xx",
        ".xxxxx..........",
        "...xxx...x...x..",
};

void push(vector<int>& clocks, int swt) {
    for (int clock=0; clock<CLOCKS; clock++) {
        if (linked[swt][clock] == 'x') {
            clocks[clock] +=3 ;
            if (clocks[clock] == 15)
                clocks[clock] = 3;
        }
    }
}

bool areAligned(vector<int>& clocks) {
    for (int i=0; i<CLOCKS; i++) {
        if (clocks[i] != 12) {
            return false;
        }
    }

    return true;
}

int solve(vector<int>& clocks, int swt) {
    if (swt == SWITCHES)
        return areAligned(clocks) ? 0 : INF;
    int ret = INF;
    for (int cnt =0; cnt < 4; cnt++) {
        ret = min(ret, cnt + solve(clocks, swt + 1));
        push(clocks, swt);
    }

    return ret;
}

int main() {
    int nrTestCases;
    int clock;
    cin >> nrTestCases;
    for (int i=0; i<nrTestCases; i++) {
        vector<int> clocks;
        for (int j = 0; j < CLOCKS; j++) {
            cin >> clock;
            clocks.push_back(clock);
        }
        int ret = solve(clocks, 0);
        if (ret == INF)
            cout << -1 << endl;
        else
            cout << ret << endl;
    }
    return 0;
}