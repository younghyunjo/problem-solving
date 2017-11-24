#include <bits/stdc++.h>

using namespace std;

#define NUMBER_OF_ALPHABETS 26

string caesarCipher(string s, int k) {
    for (auto & c : s) {
        if (isupper(c)) {
            c -= 'A';
            c += k;
            c %= NUMBER_OF_ALPHABETS;
            c += 'A';
        }
        else if (islower(c)) {
            c -= 'a';
            c += k;
            c %= NUMBER_OF_ALPHABETS;
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
