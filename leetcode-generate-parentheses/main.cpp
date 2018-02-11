#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int remain_close;
    int remain_open;

    string s = "";
    vector<string> ret;

    void doing(void) {
        if (remain_close == 0 && remain_open == 0) {
            ret.push_back(s);
            return;
        }

        if (remain_close && remain_close > remain_open) {
            s.push_back(')');
            remain_close--;
            doing();
            s.pop_back();
            remain_close++;
        }

        if (remain_open) {
            s.push_back('(');
            remain_open--;
            doing();
            s.pop_back();
            remain_open++;
        }
        return;
    }
public:
    vector<string> generateParenthesis(int n) {
        remain_open = n;
        remain_close = n;
        doing();
        return ret;
    }
};

int main() {
    Solution s;
    vector<string> ret = s.generateParenthesis(3);

    for (auto p : ret)
        cout << p << endl;

    return 0;
}