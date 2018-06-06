#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        std::map<int, int, std::greater<int>> m;

        for (auto n : nums) {
            m[n]++;
        }

        auto x = std::max_element(m.begin(), m.end(), [](const std::pair<int, int>& p1, const std::pair<int, int>& p2) {
            return p1.second < p2.second;
        });

        return x->first;
    }
};

int main() {
    Solution s;

    std::vector<int> nums = {3, 3, 1, 1, 2, 3, 4, 4, 4, 4, 3, 3, 3};
    std::cout << s.majorityElement(nums) << std::endl;
    return 0;
}
