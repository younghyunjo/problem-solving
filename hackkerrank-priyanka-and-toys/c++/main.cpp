#include <iostream>
#include <algorithm>

using namespace std;

#define ADDITION 4

int main() {
    int n;
    cin >> n;

    int weight[n] = {0,};
    for (int i=0; i<n ;i++) {
        cin >> weight[i];
    }

    sort(weight, weight + n);

    int j=0;
    int nr_buying = 0;
    while (j < n) {
        nr_buying++;
        int max_weight = weight[j] + ADDITION;
        while (weight[++j] <= max_weight);
    }

    cout << nr_buying << endl;


    return 0;
}