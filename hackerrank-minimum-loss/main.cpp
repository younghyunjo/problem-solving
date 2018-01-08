//https://www.hackerrank.com/challenges/minimum-loss/problem

#include <iostream>
#include <vector>
#include <gmpxx.h>

using namespace std;

int n;

int main() {
    cin >> n;

    vector<pair<long, int>> price;
    for (int i=0; i<n; i++) {
        long p;
        cin >> p;
        price.push_back(make_pair(p, i));
    }

    long ret = numeric_limits<long>::max();

    sort(price.begin(), price.end());
    for (int i=0; i<n-1; i++) {
        pair<long, int> buy;
        pair<long, int> sell;
        if (price[i].second < price[i+1].second) {
            buy = price[i];
            sell = price[i+1];
        }
        else {
            buy = price[i+1];
            sell = price[i];
        }

        if (buy.first - sell.first > 0) {
            ret = min(ret, buy.first - sell.first);
        }
    }

    cout << ret << endl;


    return 0;
}