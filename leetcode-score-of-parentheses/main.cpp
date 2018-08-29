//https://leetcode.com/problems/score-of-parentheses/description/
#include <iostream>
#include <stack>
#include <algorithm>

class Solution {
public:
    int scoreOfParentheses(std::string s) {
        std::stack<int> parenthesesStack;
        int currentPoint = 0;

        for (auto c : s) {
            if (c == '(') {
                parenthesesStack.push(currentPoint);
                currentPoint = 0;
            }
            else {
                currentPoint = parenthesesStack.top() + (currentPoint == 0 ? 1 : currentPoint * 2);
                parenthesesStack.pop();
            }

        }

        return currentPoint;
    }
};

int main() {
    Solution s;
    std::cout <<s.scoreOfParentheses("()()") << std:: endl;
    std::cout <<s.scoreOfParentheses("()((()()))") << std:: endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}