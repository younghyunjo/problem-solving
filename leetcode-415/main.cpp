//https://leetcode.com/problems/add-strings/description/
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry = 0;

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        int maxLength = max(num1.length(), num2.length());

        num1.append(maxLength - num1.length(), '0');
        num2.append(maxLength - num2.length(), '0');

        string ret;
        int intSum = 0;
        for (int i=0; i<maxLength; i++) {
            intSum = num1[i] - 0x30 + num2[i] - 0x30 + carry;
            carry = intSum / 10;
            ret.push_back(intSum % 10 + 0x30);
        }

        if (carry) {
            ret.push_back(carry + 0x30);
        }

        reverse(ret.begin(), ret.end());

        return ret;


    }
};

int main() {
    Solution s;
    cout<< s.addStrings("1", "9") << endl;
    return 0;
}