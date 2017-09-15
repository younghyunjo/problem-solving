#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

int cache[10001] = {-1,};

int fib(int n) {
    int& ret = cache[n];

    if (ret != -1)
        return ret;

    if (n == 0 || n == 1) {
        ret = 1;
        return ret;
    }

    ret = fib(n-1) + fib(n-2);

    return ret;
}

unordered_map<int, string> cacheString;

string stringAdd(string a, string b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int maxLength = max(a.length(), b.length());

    a.append(maxLength - a.length(), '0');
    b.append(maxLength - b.length(), '0');

    string ret;
    int carry = 0;
    int sum = 0;
    for (int i = 0; i < maxLength; i++) {
        sum = a[i] - '0' + b[i] - '0' + carry;
        carry = sum / 10;
        ret.push_back((sum%10) + '0');
    }

    if (carry) {
        ret.push_back(carry + '0');
    }

    reverse(ret.begin(), ret.end());

    return ret;
}

string fibStr(int n) {
    string ret;

    if (n == 0 || n == 1) {
        ret = "1";
        cacheString[n] = ret;
        return ret;
    }

    if (cacheString.find(n) != cacheString.end()) {
        return cacheString[n];
    }

    string prev1 = fibStr(n-1);
    string prev2 = fibStr(n-2);

    cacheString[n] = stringAdd(prev1, prev2);
    return cacheString[n];
}

void setBit(uint32_t *reg, int n) {
    (*reg) |= (1 << n);
}

void clearBit(uint32_t *reg, int n) {
    (*reg) &= ~(1 << n);
}


// To execute C++, please define "int main()"
int main() {

    cout << fibStr(0) << endl;
    cout << fibStr(1) << endl;
    cout << fibStr(5) << endl;
    cout << fibStr(9) << endl;
    cout << fibStr(10000) << endl;

    uint32_t i = 0;
    setBit(&i, 1);

    return 0;
}

