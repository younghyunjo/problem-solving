//https://leetcode.com/problems/climbing-stairs

#include <iostream>
#include <vector>

class Solution {
public:
    int climbStairs(int n) {
        dpBufferInit(n);

        for (int i=2; i<=n; i++)
            doClimbStairs(i);

        return dp[n];
    }

private:
    void doClimbStairs(int n) {
        if (n == 0 || n == 1)
            return;

        dp[n] = dp[n-1] + dp[n-2];
    }

    void dpBufferInit(int n) {
        dp = std::vector<int>(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
    }

    std::vector<int> dp;
};

int main() {
    Solution s;
    auto ret = s.climbStairs(5);
    std::cout << ret << std::endl;

    return 0;
}