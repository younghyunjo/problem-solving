//https://www.hackerrank.com/challenges/substring-diff/problem
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

static int sumVector(vector<int> v) {
    return accumulate(v.begin(), v.end(), 0);
}

int main() {
    int n;
    cin >> n;

    vector<int> primary;
    vector<int> secondary;
    int number;

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> number;
            if (i == j) {
                primary.push_back(number);
            }
            if (i+j == n-1) {
                secondary.push_back(number);
            }
        }
    }

    printf("%d\n", abs(sumVector(primary)- sumVector(secondary)));
}