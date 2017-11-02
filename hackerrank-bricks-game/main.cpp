//https://www.hackerrank.com/challenges/play-game/problem
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long int solve(int n, vector<int>& bricks) {
    vector<long long int> dp(n+10, 0);
    vector<int> jump(n+10, 0);
    vector<long long int>tmp(3, 0);

    dp[n] = bricks[n];
    dp[n-1] = bricks[n-1] + dp[n];
    dp[n-2] = bricks[n-2] + dp[n-1]

    jump[n] = 1;
    jump[n-1] = 2;
    jump[n-2] = 3;

    for (int i=n-3; i>=0; i--) {
        tmp[0] = bricks[i] + dp[i + 1 + jump[i+1]];
        tmp[1] = bricks[i] + bricks[i+1] + dp[i + 2 + jump[i+2]];
        tmp[2] = bricks[i] + bricks[i+1] + bricks[i+2] +  dp[i + 3 + jump[i+3]];

        auto it = max_element(tmp.begin(), tmp.end());
        dp[i] = *it;
        jump[i] = distance(tmp.begin(), it) + 1;
    }

    return dp[1];
}

int main() {
    int t;
    for (cin >> t; t; t--) {
        int n;
        cin >> n;
        vector<int> bricks(n+1, 0);
        for (int i=1; i<=n ;i++) {
            cin >> bricks[i];
        }
        printf("%lld\n", solve(n, bricks));
    }
    return 0;
}