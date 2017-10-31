//https://www.hackerrank.com/challenges/stockmax/problem
#include <iostream>
#include <vector>

using namespace std;

long long int profit2(vector<int>& price) {
    long long int profit = 0;
    int start = price.size()-1;
    for (int i=price.size()-2; i>=0; i--) {
        if (price[i] < price[start]) {
            profit += price[start] - price[i];
        }
        else {
            start = i;
        }
    }
    return profit;
}

int main() {
    int nrTestcase;
    cin >> nrTestcase;

    for (int i=0; i<nrTestcase; i++) {
        int n;
        cin >> n;
        vector<int> price(n, 0);

        for (int j=0; j<n; j++) {
            cin >> price[j];
        }

        printf("%lld\n", profit2(price));
    }
    return 0;
}