#include <iostream>

using namespace std;

#define NUMBER_OF_ALPHABET 26

string transform(string str) {
    int hits[NUMBER_OF_ALPHABET] = {0,};

    int i=0;
    for (i=0; i<str.size(); i++) {
        int hitsIndex = str[i] - 'a';
        if (hits[hitsIndex])
            break;
        hits[hitsIndex] +=1;
    }

    for (int j=i; j<str.size(); j++) {
        int hitsIndex = str[j] - 'a';
        int charNumber = str[j] + hits[hitsIndex];
        if (charNumber > 'z') {
            charNumber = ((charNumber-'z'-1) % NUMBER_OF_ALPHABET) + 'a';
        }

        hits[hitsIndex] += 1;
        str[j] = charNumber;
    }

    return str;
}

int main() {
    int nrTestcase;
    cin >> nrTestcase;
    for (int i=0; i<nrTestcase; i++) {
        int length;
        cin >> length;

        string str;
        cin >> str;
        cout << transform(str) << endl;
    }

    return 0;
}