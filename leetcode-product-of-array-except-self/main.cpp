//https://leetcode.com/problems/product-of-array-except-self/description/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> fromBegin(n);
        fromBegin[0]=1;
        vector<int> fromLast(n);
        fromLast[0]=1;

        for(int i=1;i<n;i++){
            fromBegin[i]=fromBegin[i-1]*nums[i-1];
            fromLast[i]=fromLast[i-1]*nums[n-i];
        }

        vector<int> res(n);
        for(int i=0;i<n;i++){
            res[i]=fromBegin[i]*fromLast[n-1-i];
        }
        return res;
    }
};

int main() {
    vector<int> input = {1, 2, 3, 4};
    vector<int> input2 = {0, 0};

    Solution s;
    vector<int> ret = s.productExceptSelf(input2);
    for (auto i : ret)
        cout << i << endl;

    return 0;
}