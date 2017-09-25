//https://www.hackerrank.com/challenges/simple-array-sum
#include <bits/stdc++.h>

using namespace std;

int simpleArraySum(int n, vector <int> ar) {
    int sum = 0;
    for (auto& i :ar) {
        sum += i;
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for(int ar_i = 0; ar_i < n; ar_i++){
       cin >> ar[ar_i];
    }
    int result = simpleArraySum(n, ar);
    cout << result << endl;
    return 0;
}
