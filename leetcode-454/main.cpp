//https://leetcode.com/problems/4sum-ii/description/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;



class Solution {
public:
    int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D) {
        unordered_map<int, int> ab;
        for (auto a : A) {
            for (auto b : B) {
                ++ab[a+b];
            }
        }

        int ret = 0;
        for (auto &c : C) {
            for (auto &d : D) {
                auto it = ab.find(0 - c -d);
                if (it != ab.end()) {
                    ret += it->second;
                }
            }
        }

        return ret;
    }
};

int main() {
    Solution s;
    vector<int> a, b, c, d;
    cout << s.fourSumCount(a, b, c, d) << endl;
    return 0;
}