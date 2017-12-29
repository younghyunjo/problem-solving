#include <iostream>
#include <vector>

using namespace std;


void merge(vector<int>& nums, int l, int m, int r) {
    vector<int> sorted;

    int i = l;
    int j = m+1;

    while (i <=m && j <=r)
    if (nums[i] < nums[j]) {
        sorted.push_back(nums[i]);
        i++;
    }
    else
    {
        sorted.push_back(nums[j]);
        j++;
    }

    while (i<=m) {
        sorted.push_back(nums[i++]);
    }
    while(j<=r) {
        sorted.push_back(nums[j++]);
    }

    for (int k=0; k<sorted.size(); k++) {
        nums[l++] = sorted[k];
    }
}

void mergesort(vector<int>& nums, int l, int r) {
    if (l >= r)
        return;

    int m = (l+r)/2;
    mergesort(nums, l, m);
    mergesort(nums, m+1, r);
    merge(nums, l, m, r);
}

int main() {
    vector<int> input = {38, 27, 43, 3, 9, 82, 10};
    mergesort(input, 0, input.size()-1);
    for (auto n : input)
        cout << n << endl;
    return 0;
}