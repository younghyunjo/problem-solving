#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> orders;
    for (int i=0; i<n ;i++) {
        int t, d;
        cin >> t >> d;
        orders.push_back(make_pair(t+d, i+1));
    }

    sort(orders.begin(), orders.end());

    for (auto& o : orders) {
        printf("%d ", o.second);
    }

    return 0;
}