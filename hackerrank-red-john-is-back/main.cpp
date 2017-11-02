//https://www.hackerrank.com/challenges/red-john-is-back/problem

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int numberOfPrimeNunber(long long int number) {
    if (number <= 1)
        return 0;

    vector<int> numbers(number+1, 1);

    for (int i=2; i<=number; i++) {
        if (numbers[i] == 0)
            continue;

        for (int j=i+i; j<=number; j+=i) {
            numbers[j] = 0;
        }
    }

    return count(numbers.begin() + 2, numbers.end(), 1);
}

int solve(int n) {
    if (n <= 3)
        return 0;

    vector<long long int> dp(n+1, 0);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;

    for (int i=4; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-4];
    }

    return numberOfPrimeNunber(dp[n]);
}

int main() {
    int t;
    for (cin >> t; t; t--) {
        int n;
        cin >> n;
        printf("%d\n", solve(n));
    }

    return 0;
}