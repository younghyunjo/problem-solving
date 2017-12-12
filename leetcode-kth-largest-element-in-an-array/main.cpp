//https://leetcode.com/problems/kth-largest-element-in-an-array/description/
#include <iostream>
#include <vector>


using namespace std;

class Solution {
private:
    void swap(vector<int>& nums, int a, int b) {
        int k = nums[a];
        nums[a] = nums[b];
        nums[b] = k;
    }

    int partition(vector<int>& nums, int lo, int hi) {
        int pivot = nums[hi];
        int j = lo;
        for (int i=lo; i<hi; i++) {
            if (nums[i] < pivot) {
                swap(nums, j, i);;
                j++;
            }
        }
        swap(nums, j, hi);
        return j;
    }

    void quicksort(vector<int> &nums, int lo, int hi) {
        if (lo > hi)
            return;

        int p = partition(nums,lo, hi);
        quicksort(nums, lo, p-1);
        quicksort(nums, p+1, hi);
    }

public:
    int findKthLargest(vector<int> &nums, int k) {
        quicksort(nums, 0, nums.size()-1);

        return nums[nums.size() - k];
    };
};

int main() {
    vector<int> input = {3, 2, 1, 10, -2, 39, 38, 28, 38, 100};
    class Solution s;
    cout << s.findKthLargest(input, 2) << endl;
    return 0;
}