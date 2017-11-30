#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define NR_ALPHABET 26

string solve(void) {
    bool hits[NR_ALPHABET];
    memset(hits, false, sizeof(hits));

    string a, b;
    cin >> a  >> b;
    for (auto c: a) {
        hits[c - 'a'] = true;
    }

    for (auto c: b) {
        if (hits[c - 'a']) {
            return "YES";
        }
    }

    return "NO";

}

int main() {
    int n;
    cin >> n;

    for (int i=0; i<n; i++) {
        cout << solve() << endl;
    }

    return 0;
}