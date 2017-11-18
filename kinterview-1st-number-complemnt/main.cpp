#include <iostream>

using namespace std;

int findHighestOne(int n) {
    int i;
    for (i=31; i>=0; i--) {
        if (n & (1<<i))
            break;
    }

    return i;
}

int getIntegerComplement(int n) {
    int highestOne = findHighestOne(n);
    n = ~n;

    for (int i=31; i>highestOne; i--)
        n &= ~(1<<i);

    return n;
}

int main() {
    printf("%x\n", 50);
    printf("%x\n", getIntegerComplement(50));
    //cout << getIntegerComplement(50) << endl;
    //cout << getIntegerComplement(100) << endl;


    return 0;
}