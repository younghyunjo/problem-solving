//https://www.hackerrank.com/challenges/two-robots/problem
//http://blog.pmatias.com/2016/03/14/hackerrank-w19-1/#mjx-eqn-dp1

#include <iostream>
#include <vector>

using namespace std;

static int distance(int start, int pickup, int putdown) {
    return abs(start - pickup) + abs(pickup - putdown);

}

int solve(int M, int N, vector<pair<int, int>>& query)
{
    vector<vector<int>> dp(N+2, vector<int>(N+1, 0));


    for (int i=N; i>0; i--) {
        int r1 = query[i-1].second;
        int r2 = query[i].first;
        for (int j=0; j<i; j++) {
            if (j != 0)
                r2 = query[j].second;
            dp[i][j] = abs(query[i].second - query[i].first) +
                       min(
                               dp[i+1][j] + abs(r1 - query[i].first),
                               dp[i+1][i-1] + abs(r2 - query[i].first)
                       );
        }
    }

    return abs(query[1].first - query[1].second) + min(dp[2][1], dp[2][0]);
}

int main() {
    int T;
    cin >> T;
    for (int i=0; i<T; i++) {
        int M, N;
        cin >> M >> N;
        vector<pair<int, int>> query(N+1, pair<int, int>(0, 0));

        for (int j=1; j<=N; j++) {
            cin >> query[j].first >> query[j].second;
        }

        printf("%d\n", solve(M, N, query));

    }

    return 0;
}