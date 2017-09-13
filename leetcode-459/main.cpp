// https://leetcode.com/problems/repeated-substring-pattern/description/
#include <iostream>
#include <cstring>

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int left, right;

        if (s.size() % 2) {
            right = s.size() / 2 + 1;
            left  = s.size() / 2;
        }
        else {
            left = right = s.size() / 2;
        }

        while(right < s.size() ) {
            if (memcmp(&s[0], &s[right], s.size() - right) == 0) {
                if (memcmp(&s[0], &s[left], right - left) == 0) {
                    return true;
                }
                return false;
            }
            else {
                right++;
                left--;
            }
        }
        return false;

    }
};

int main() {
    Solution s;
    cout << s.repeatedSubstringPattern("a") << endl;
    cout << s.repeatedSubstringPattern("") << endl;
    cout << s.repeatedSubstringPattern("ababab") << endl;
    cout << s.repeatedSubstringPattern("abcabc") << endl;
    cout << s.repeatedSubstringPattern("abab") << endl;
    cout << s.repeatedSubstringPattern("abcabcabc") << endl;
    cout << s.repeatedSubstringPattern("abcabcabcabcabc") << endl;
    cout << s.repeatedSubstringPattern("aabaaba") << endl;
    cout << s.repeatedSubstringPattern("abcabcabcabcabcabcabcabcabcabc") << endl;
    
    return 0;
}