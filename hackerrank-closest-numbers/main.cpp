//https://www.hackerrank.com/challenges/closest-numbers
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static int n;
static vector<int> a;

void solve() {
    sort(a.begin(), a.end());

    vector<pair<int, int>> pairs;
    long long int minDifference = numeric_limits<long long int>::max();
    long long int difference;

    for (int i=0; i<n-1; i++) {
        difference = abs(a[i] - a[i+1]);
        if (difference < minDifference) {
            minDifference = difference;
            pairs.clear();
            pairs.push_back(make_pair(a[i], a[i+1]));
        }
        else if (difference == minDifference) {
            pairs.push_back(make_pair(a[i], a[i+1]));
        }
    }

    for (auto& p : pairs) {
        printf("%d %d ", p.first, p.second);
    }
}

int main() {
    cin >> n;
    a.assign(n, 0);
    for (int& i : a) {
        cin >> i;
    }

    solve();

    return 0;
}