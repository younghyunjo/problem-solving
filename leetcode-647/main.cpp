//https://leetcode.com/problems/palindromic-substrings/description/
#include <iostream>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        for (int i=0; i<s.length(); i++) {
            count += _countSubstring(s, i, i);
            count += _countSubstring(s, i, i+1);
        };

        return count;
    }

private:
    int _countSubstring(string s, int left, int right) {
        int count = 0;
        while (left >= 0 && right < s.length() && s[left] == s[right])
            count++, left--, right++;
        return count;
    }
};


int main() {
    string str("aba");
    string str2("aaa");
    Solution s;
    cout << s.countSubstrings(str) << endl;
    cout << s.countSubstrings(str2) << endl;

    return 0;
}