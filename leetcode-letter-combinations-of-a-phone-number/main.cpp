//https://leetcode.com/problems/letter-combinations-of-a-phone-number/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    std::vector<std::string> letterCombinations(std::string digit) {
        std::vector<std::string> ret;
        for( auto d : digit) {
            int index = d - '0';
            ret = combine(ret, digit2characters[index]);
        }
        return ret;
    }


private:
    std::vector<std::string> combine(std::vector<std::string>strings, std::string characters) {
        std::vector<std::string> ret;

        if (strings.empty()) {
            for (auto c : characters) {
                ret.push_back(std::string{c});
            }
            return ret;
        }

        for (auto s : strings) {
            for (auto c : characters) {
                ret.push_back(s + c);
            }
        }
        return ret;
    }

    const std::vector<std::string> digit2characters = {
            {""},
            {""},
            {"abc"},
            {"def"},
            {"ghi"},
            {"jkl"},
            {"mno"},
            {"pqrs"},
            {"tuv"},
            {"wxyz"},

    };
};

int main() {
    Solution s;
    s.letterCombinations("10");

    return 0;
}