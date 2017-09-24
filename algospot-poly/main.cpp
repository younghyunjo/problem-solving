#include <iostream>
#include <cstring>

using namespace std;
int cache[101][101];

int poly(int numberOfBoxes, int numberOfPrevRowBoxes) {
    if (numberOfBoxes <= 1) {
        return 1;
    }

    int& ret = cache[numberOfBoxes][numberOfPrevRowBoxes];
    if (ret != -1)
        return ret;

    ret = 0;
    for (int i=1; i<=numberOfBoxes; i++) {
        ret += (numberOfPrevRowBoxes + i -1) * poly(numberOfBoxes-i, i);
    }

    return ret;
}

int main() {
    int numberOfTestCases;
    cin >> numberOfTestCases;

    for (int i=0; i<numberOfTestCases;i++) {
        memset(cache, -1, sizeof(cache));
        int n;
        cin >> n;
        cout << (poly(n, 0) + 10000000) % 10000000 << endl;
    }

    return 0;
}