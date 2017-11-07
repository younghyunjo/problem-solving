//https://www.hackerrank.com/challenges/turn-off-the-lights/problem
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

long long int solve(int n, int k, vector<int>& lights) {
    long long int minCost = numeric_limits<long long int>::max();

    for(int i=0; i<k+1; i++) {
        int switchPushIndex = i;
        long long int cost = 0;

        while (switchPushIndex < n) {
            cost += lights[switchPushIndex];
            switchPushIndex += 2 * k + 1;
        }

        if (n+k <= switchPushIndex) {
            minCost = min(minCost, cost);
        }
    }
    return minCost;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> lights(n, -1);

    for (auto& l : lights)
        cin >> l;

    printf("%lld\n", solve(n, k, lights));

    return 0;
}