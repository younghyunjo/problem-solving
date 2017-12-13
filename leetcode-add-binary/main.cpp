//https://leetcode.com/problems/add-binary/description/
#include <iostream>
#include <algorithm>

using namespace std;

#define A2N(x) ((x) - '0')
#define N2A(x) ((x) + '0')

class Solution {
public:
    string addBinary(string a, string b) {
        int length = a.size() > b.size() ? a.size() : b.size();

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        a.append(length - a.size(), '0');
        b.append(length - b.size(), '0');

        string sum;
        int carry = 0;
        int s = 0;

        for (int i=0; i<length; i++) {
            s = A2N(a[i]) + A2N(b[i]) + carry;
            if (s == 2) {
                s = 0;
                carry = 1;
            }
            else if (s == 3) {
                s = 1;
                carry = 1;
            }
            else {
                carry = 0;
            }
            sum.push_back(N2A(s));
        }

        if (carry)
            sum.push_back(N2A(carry));

        reverse(sum.begin(), sum.end());
        return sum;
    }
};

int main() {
    Solution s;

    cout << s.addBinary("10011", "1") << endl;
    return 0;
}