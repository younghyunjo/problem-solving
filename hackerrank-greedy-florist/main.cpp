#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int solve(int n, int k, vector<int>& costs) {
    if (k>=n) {
        return accumulate(costs.begin(), costs.end(), 0);
    }

    int p = 0;
    int pTemp = 0;
    int divided = n / k;
    int x = 1;

    while (divided--) {
        pTemp = accumulate(costs.begin(), costs.begin() + k , 0);
        costs.erase(costs.begin(), costs.begin() + k);

        p += (pTemp * x);
        x++;
    }

    pTemp = accumulate(costs.begin(), costs.end(), 0);
    p += (pTemp * x);

    return p;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> costs;
    int cost;
    for (int i=0; i<n; i++) {
        cin >> cost;
        costs.push_back(cost);
    }

    sort(costs.begin(), costs.end(), greater<int>());


    cout << solve(n, k, costs) << endl;
    return 0;
}