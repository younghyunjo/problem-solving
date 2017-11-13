//https://www.hackerrank.com/challenges/common-child/problem

#include <iostream>
#include <vector>

using namespace std;

string s1;
string s2;
vector<vector<int>> dp;

int solve(int i, int j) {
    if (i<0 || j<0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    else if (s1[i] == s2[j]) {
        dp[i][j] = solve(i - 1, j - 1)+1;
        return dp[i][j];
    }
    else {
        dp[i][j] = max(solve(i, j - 1), solve(i - 1, j));
        return dp[i][j];
    }
}

int main() {
    cin >> s1 >> s2;
    dp.assign(s1.length(), vector<int>(s2.length(), -1));
    printf("%d\n", solve(s1.length()-1, s2.length()-1));
}
