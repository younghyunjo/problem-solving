//https://www.hackerrank.com/challenges/sherlock-and-cost
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int N;
vector<int> B;
vector<int> cacheLow;
vector<int> cacheHigh;

int findS(void) {

    for (int i=1; i<N; i++) {
        cacheLow[i] = max(cacheLow[i-1], cacheHigh[i-1] + abs(1-B[i-1]));
        cacheHigh[i] = max(cacheLow[i-1] + abs(B[i]-1), cacheHigh[i-1] + abs(B[i] - B[i-1]));
    }

    return max(cacheLow[N-1], cacheHigh[N-1]);
}


int main() {
    int nrTestcase = 0;

    cin >> nrTestcase;

    for (int i=0; i<nrTestcase; i++) {
        B.clear();
        cacheLow.clear();
        cacheHigh.clear();

        cin >> N;
        B.assign(N, 0);
        cacheLow.assign(N+1, 0);
        cacheHigh.assign(N+1, 0);

        for (int j=0; j<N; j++) {
            cin >> B[j];
        }

        cout << findS() << endl;
    }

    return 0;
}
