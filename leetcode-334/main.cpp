//https://leetcode.com/problems/reverse-string/description/

#include <iostream>

using namespace std;

class Solution {
public:
    string reverseString(string s) {
        int i = 0, j = s.size() -1;
        while (i < j) {
            swap(s[i++], s[j--]);
        }
        return s;
    }
};

int main() {
    Solution s;
    string s1("hello");
    cout << s.reverseString(s1) << endl;
    return 0;
}