#include <iostream>
#include <numeric>
#include <limits>
#include <vector>
#include <cstring>

using namespace std;

const int INTMAX = numeric_limits<int>::max();

int nr;
int numbers[101];
int cache[101][11];

int deviation(int from, int to) {
    return accumulate(&numbers[from], &numbers[to], 0);
}

int quantize(int start, int group) {
    int& ret = cache[start][group];
    if (ret != -1)
        return ret;

    if (group == 0)
        return deviation(start, nr-1);

    ret = INTMAX;
    for (int i=0; i<nr; i++) {
        ret = std::min(ret, deviation(start, i) + quantize(start+i, group-1));
    }

    return ret;
}

int main() {
    int nrTestCases;
    cin >> nrTestCases;
    for (int i=0; i<nrTestCases; i++) {
        int nrGroup;
        cin >> nr >> nrGroup;
        for (int j=0; j<nr; j++)
            cin >> numbers[j];

        memset(cache, -1, sizeof(cache));

        //quantize(0, nrGroup);

    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
