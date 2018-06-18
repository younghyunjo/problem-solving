#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<pair<int, int>> makeSortedNumberAndIndex(vector<int>& nums) {
        vector<pair<int, int>> sortedNumberAndIndex;

        for (int i=0; i<nums.size(); i++) {
            sortedNumberAndIndex.push_back(make_pair(nums[i], i));
        }

        sort(sortedNumberAndIndex.begin(), sortedNumberAndIndex.end());

        return sortedNumberAndIndex;
    }
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        vector<pair<int,int>> lists = makeSortedNumberAndIndex(nums);

        int l = 0;
        int r = nums.size()-1;

        while (l < r) {
            int tmp = target - lists[r].first;
            if (lists[l].first == tmp) {
                ret.push_back(lists[l].second);
                ret.push_back(lists[r].second);
                break;
            }
            else if (lists[l].first < tmp) {
                l++;
            }
            else {
                r--;
            }
        }
        return ret;
    }
};


int main() {
    vector<int> in = {0, 4, 3, 0};
    Solution s;
    vector<int> r = s.twoSum(in, 0);

    if (!r.empty())
        cout << r[0] << " " << r[1] << endl;
    return 0;

}