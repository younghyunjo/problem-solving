#include <bits/stdc++.h>

using namespace std;

string caesarCipher(string s, int k) {

    for (char& c : s) {
        if (isupper(c)) {
            c -= 'A';
            c += k;
            c %= 26;
            c += 'A';
        }
        else if (islower(c)) {
            c -= 'a';
            c += k;
            c %= 26;
            c += 'a';
        }
        else
            continue;
    }

    return s;
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int k;
    cin >> k;
    string result = caesarCipher(s, k);
    cout << result << endl;
    return 0;
}
