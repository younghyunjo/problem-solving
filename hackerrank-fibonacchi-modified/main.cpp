//https://www.hackerrank.com/challenges/fibonacci-modified?h_r=next-challenge&h_v=zen
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int t1 = 0;
int t2 = 0;
int n = 0;

#define CHAR_TO_INT(c)     ((c)-0x30)
#define INT_TO_CHAR(i)       ((i)+0x30)

vector<string> cache;

string addReserveString(string s1, string s2) {
    int biggerLength = max(s1.length(), s2.length());

    s1.append(biggerLength - s1.length(), '0');
    s2.append(biggerLength - s2.length(), '0');

    int carry = 0;
    string sum;
    for (int i=0; i<biggerLength; i++) {
        int s = CHAR_TO_INT(s2[i]) + CHAR_TO_INT(s1[i]) + carry;
        sum.push_back(INT_TO_CHAR(s%10));
        carry = s / 10;
    }

    if (carry)
        sum.push_back(INT_TO_CHAR(carry%10));

    return sum;
}

string addString(string s1, string s2) {
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());

    string sum = addReserveString(s1, s2);

    reverse(sum.begin(), sum.end());

    return sum;
}


string muliplyReversedString(string s1, string s2) {
    int biggerLength = max(s1.length(), s2.length());

    s1.append(biggerLength - s1.length(), '0');
    s2.append(biggerLength - s2.length(), '0');

    string mul = "0";

    for (int  i=0; i<biggerLength; i++) {
        int carry = 0;

        string m1;
        m1.append(i, 0x30);

        for (int j=0; j<biggerLength;j++) {
            int tmp = (CHAR_TO_INT(s1[j])) * (CHAR_TO_INT(s2[i])) + carry;
            m1.push_back(INT_TO_CHAR(tmp%10));
            carry = tmp/10;
        }


        if (carry)
            m1.push_back(INT_TO_CHAR(carry));

        mul = addReserveString(m1, mul);
    }
    return mul;
}

string multiplyString(string s1, string s2) {
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());

    string mul = muliplyReversedString(s1, s2);

    reverse(mul.begin(), mul.end());
    return mul;
}


string powOfTwoString(string s) {
    return muliplyReversedString(s, s);
}

string fibonacciModified(int n) {

    if (n == 1 || n == 2)
        return cache[n];
    if (cache[n] != "") {
        return cache[n];
    }

    cache[n] = addReserveString(fibonacciModified(n-2), powOfTwoString(fibonacciModified(n-1)));

    return cache[n];
}


int main() {
    //cout << powOfTwoString("27") << endl;
    //return 0;
    cin >> t1 >> t2 >> n;
    cache.assign(n+1, "");
    cache[1] = to_string(t1);
    cache[2] = to_string(t2);

    for (int i=3; i<=n; i++) {
        fibonacciModified(i);
    }

    reverse(cache[n].begin(), cache[n].end());
    cout << cache[n] << endl;

    return 0;
}
