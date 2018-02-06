//https://leetcode.com/problems/top-k-frequent-elements/description/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (auto n : nums) {
            freq[n]++;
        }

        vector<vector<int>> bucket(nums.size()+1);

        for(auto f : freq) {
            bucket[f.second].push_back(f.first);
        }

        vector<int> ret;
        for (int i = bucket.size()-1; i>=0;  i--) {
            for(auto j : bucket[i]) {
                ret.push_back(j);
                if (ret.size() == k)
                    return ret;
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