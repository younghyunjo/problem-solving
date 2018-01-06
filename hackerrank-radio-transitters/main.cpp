//https://www.hackerrank.com/challenges/hackerland-radio-transmitters/problem
#include <bits/stdc++.h>

using namespace std;

int n;
int k;
vector<int> x;

int hackerlandRadioTransmitters(void) {
    sort(x.begin(), x.end());

    int ret = 0;
    int i = 0;
    int range = 0;
    while (i < x.size()) {
        range = x[i] + k;
        while (i < n && x[i] <= range) i++;
        range = x[--i] + k;
        ret++;
        while (i < n && x[i] <= range) i++;
    }


    return ret;
}

int main() {
    cin >> n >> k;
    x.assign(n, 0);
    for(int x_i = 0; x_i < n; x_i++){
        cin >> x[x_i];
    }

    int result = hackerlandRadioTransmitters();
    cout << result << endl;
    return 0;
}
