//https://leetcode.com/problems/queue-reconstruction-by-height/description/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        auto comp = [](const pair<int, int>& p1, const pair<int, int>& p2) {
            return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second);
        };
        sort(people.begin(), people.end(), comp);

        vector<pair<int, int>> ret;
        for (auto& p : people)
            ret.insert(ret.begin() + p.second, p);
        return ret;
    }
};

int main() {
    vector<pair<int, int>> people = {
            make_pair(7, 0),
            make_pair(4, 4),
            make_pair(7, 1),
            make_pair(5, 0),
            make_pair(6, 1),
            make_pair(5, 2),
    };

    Solution s;
    s.reconstructQueue(people);
    return 0;
}