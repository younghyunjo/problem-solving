#include <iostream>
#include <limits>
#include <cstring>

const long long NEGINF = std::numeric_limits<long long>::min();
int A[101], B[101];
int n, m;
int cache[101][101];


int jlis(int indexA, int indexB) {
    int& ret = cache[indexA+1][indexB+1];
    if (ret != -1) return ret;

    ret = 2;
    long long a = (indexA == -1 ? NEGINF : A[indexA]);
    long long b = (indexB == -1 ? NEGINF : B[indexB]);
    long long maxElement = std::max(a, b);

    for (int nextA = indexA + 1; nextA < n; ++nextA)
        if (maxElement < A[nextA])
            ret = std::max(ret, jlis(nextA, indexB) + 1);
    for (int nextB = indexB + 1; nextB < n; ++nextB)
        if (maxElement < B[nextB])
            ret = std::max(ret, jlis(indexA, nextB) + 1);
    return ret;
}

void jlis_do() {
    int aLen, bLen;
    std::cin >> aLen >> bLen;

    A[0] = -1;
    for (int i=1; i<=aLen; i++) {
        std::cin >> A[i];
    }

    B[0] = -1;
    for (int i=1; i<=bLen; i++) {
        std::cin >> B[i];
    }

    memset(cache, -1, sizeof(cache));
    std::cout << jlis(-1, -1) << std::endl;
}

int main() {
    int nrTestCase = 0;
    std::cin >> nrTestCase;

    for (int i=0; i<nrTestCase; i++)
        jlis_do();

    return 0;
}