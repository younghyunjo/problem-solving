//https://leetcode.com/problems/reverse-string/description/

#include <iostream>

using namespace std;

class Solution {
public:
    string reverseString(string s) {
        if (s.empty()) {
            return s;
        }

        string ret;
        for (auto it = s.end() -1 ; it >= s.begin(); it--) {
            cout << *it << endl;
            ret.push_back(*it);
        }

        return ret;
    }
};

int main() {
    Solution s;
    string s1("hello");
    cout << s.reverseString(s1) << endl;
    return 0;
}