#include <bits/stdc++.h>

using namespace std;

#define NUMBER_OF_ALPHABETS 26

string caesarCipher(string s, int k) {
    for (auto & c : s) {
        if (!isalpha(c))
            continue;

        char offset = isupper(c) ? 'A' : 'a';
        c = ((c-offset + k) % NUMBER_OF_ALPHABETS) + offset;
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
