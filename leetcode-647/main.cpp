//https://leetcode.com/problems/palindromic-substrings/description/
#include <iostream>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;

        for (int i=0; i<s.length(); i++)
            for (int j=i; j<s.length(); j++)
                if (isPalindromicString(s, i, j))
                    count++;
        return count;
    }

private:
    bool isPalindromicString(string s, int begin, int end) {
        if (begin == end)
            return true;

        for (int i=0; i<(end-begin+1)/2; i++) {
            if (s[begin + i] != s[end - i])
                return false;
        }
        return true;
    }
};


int main() {
    string str("abaabc");
    Solution s;
    cout << s.countSubstrings(str) << endl;

    return 0;
}