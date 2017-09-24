#include <cmath>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int N, K, unfairness = INT_MAX;
    cin >> N >> K;
    int list[N];
    for (int i=0; i<N; i++)
        cin >> list[i];

    sort (list, list+N);

    int this_unfairness;
    for (int i=0; i<=N-K; i++) {
        this_unfairness = list[i+K-1] - list[i];
        unfairness = this_unfairness < unfairness ? this_unfairness : unfairness;
    }

    cout << unfairness << "\n";
    return 0;
}