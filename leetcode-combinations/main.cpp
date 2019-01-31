//https://leetcode.com/problems/combinations/submissions/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> choosen;
        vector<vector<int>> combinations;

        doCombine(n, k, 1, choosen, combinations);
        return combinations;
    }

private:
    void doCombine(int n, int k, int start, vector<int> choosen, vector<vector<int>>& combinations) {
        if (choosen.size() == k) {

            combinations.push_back(choosen);
            return;
        }

        for (int i = start; i<=n ;i++) {
            choosen.push_back(i);
            doCombine(n, k, i+1, choosen, combinations);
            choosen.pop_back();
        }
    }
};

int main() {
    Solution s;
    auto r = s.combine(4, 2);
    for (auto i : r) {
        for (auto j : i) {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}