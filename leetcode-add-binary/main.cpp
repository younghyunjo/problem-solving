//https://leetcode.com/problems/add-binary/description/
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string sum = "";
        int i = a.size()-1;
        int j = b.size()-1;
        int carry = 0;


        while (i >= 0 || j >= 0 || carry) {
            if (i >= 0) {
                carry += (a[i--] - '0');
            }
            if (j >= 0) {
                carry += (b[j--] - '0');
            }

            sum = char(carry % 2 + '0') + sum;
            carry = carry / 2;
        }

        return sum;
    }
};

int main() {
    Solution s;

    cout << s.addBinary("10011", "1") << endl;
    return 0;
}