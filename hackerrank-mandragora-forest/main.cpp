//https://www.hackerrank.com/challenges/mandragora/problem
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> mandragora;

long long int solve(long long int sum) {
    sort(mandragora.begin(), mandragora.end());
    int s = 1;
    long long int p = sum;
    for (auto& i : mandragora) {
        s++;
        sum -= i;
        if (p < sum * s) {
            p = sum *s;
        }
        else
            break;
    }

    return p;
}

int main() {
    int t;
    for (cin >> t; t; t--){
        int n;
        cin >> n;
        mandragora.assign(n, 0);

        long long int sum = 0;
        for (int i=0; i<n; i++) {
            cin >> mandragora[i];
            sum += mandragora[i];
        }
        printf("%lld\n", solve(sum));

        mandragora.clear();
    }
    return 0;
}
