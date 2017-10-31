//https://www.hackerrank.com/challenges/maxsubarray/problem

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve2(vector<int> &a) {
    long long int maxSubarray = *max_element(a.begin(), a.end());
    if (maxSubarray <= 0) {
        printf("%lld %lld\n", maxSubarray, maxSubarray);
        return;
    }

    long long int prevSum = 0;
    long long int maxSubsequence = 0;
    maxSubarray = 0;
    for (auto &i : a) {
        if (i > 0) {
            maxSubsequence += i;
        }

        if (prevSum + i > 0) {
            prevSum += i;
        }
        else {
            prevSum = 0;
        }

        maxSubarray = max(maxSubarray, prevSum);
    }

    printf("%lld %lld\n", maxSubarray, maxSubsequence);
    return;
}

int main() {
    int nrTestcase;
    cin >> nrTestcase;

    for (int i=0; i<nrTestcase; i++) {
        int nrArray;
        cin >> nrArray;
        vector<int> a(nrArray, 0);

        for (int j=0; j<nrArray; j++) {
            cin >> a[j];
        }
        solve2(a);
    }

    return 0;
}