#include <bits/stdc++.h>
#include <vector>

using namespace std;

vector<vector<long long>> dp;
long long getWays(long n, vector < long > c){
    dp.assign(n+1, vector<long long>(c.size(), 0));

    for (int i=0; i<c.size(); i++) {
        dp[0][i] = 1;
    }

    for (int i=1; i<=n; i++) {
        for (int j=0; j<c.size(); j++) {
            int include = 0;
            int exclude = 0;

            if (i - c[j] >= 0) {
                include = dp[i-c[j]][j];
            }

            if (j-1 >= 0) {
                exclude = dp[i][j-1];
            }

            dp[i][j] = include + exclude;
        }
    }

    for (int i=0; i<=n; i++) {
        for (int j=0; j<c.size(); j++) {
            cout<< dp[i][j] << " ";
        }
        cout << endl;
    }

    cout << "n:" << n << endl;
    cout << "c.size():" << c.size() << endl;

    return dp[n][c.size()-1];
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<long> c(m);
    for(int c_i = 0; c_i < m; c_i++){
        cin >> c[c_i];
    }

    long long ways = getWays(n, c);
    printf("%lld", ways);
    return 0;
}