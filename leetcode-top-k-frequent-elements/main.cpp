//https://leetcode.com/problems/top-k-frequent-elements/description/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (auto n : nums) {
            freq[n]++;
        }

        vector<int>ret;

        priority_queue<pair<int, int>> pq;
        for (auto it = freq.begin(); it != freq.end(); it++) {
            pq.push(make_pair(it->second, it->first));
            if (pq.size() > (int)freq.size() - k) {
                ret.push_back(pq.top().second);
                pq.pop();
            }
        }

        return ret;
    }
};

int main() {
    vector<int> input = {1, 1, 1, 2, 2, 3};
    int k = 2;

    Solution s;
    s.topKFrequent(input, k);

    return 0;
}