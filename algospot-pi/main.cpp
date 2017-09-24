#include <iostream>
#include <cstring>

using namespace std;

const int INF = 987654321;

int cache[10002];
string N;

int point(int a, int b) {
    string M = N.substr(a, b - a + 1);

    if (M == string(M.size(), M[0]))    return 1;

    bool progressive = true;
    for (int i = 0; i < M.size() - 1; i++) {
        if (M[i+1] - M[1] != M[1] - M[0])
            progressive = false;
    }

    if (progressive && abs(M[1] - M[0]) == 1) {
        return 2;
    }

    bool alternative = true;
    for (int i = 0; i < M.size(); i++) {
        if (M[i] != M[i%2]) {
            alternative = false;
        }
    }

    if (alternative)
        return 4;

    if (progressive)
        return 5;

    return 10;
}

int pi(int start) {
    if (start >= N.size()) {
        return 0;
    }

    int& ret = cache[start];
    if (ret != -1) {
        return ret;
    }

    ret = INF;
    for (int i=3; i<=5; i++) {
        ret = min(ret, point(start, start + i-1) + pi(start + i));
    }

    return ret;
}

int main() {
    int testcases;

    std::cin >> testcases;
    for (int i=0; i<testcases; i++) {
        N.clear();
        memset(cache, -1, sizeof(cache));
        std::cin >> N;
        cout << pi(0) << endl;
    }

    return 0;
}