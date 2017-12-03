#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int nrSubtree(vector<vector<int>>& edgeTable, vector<int>& history, vector<int>& dp) {
    int nr = 0;
    fill(dp.begin(), dp.end(), 0);

    for (int i=1; i<=50; i++) {
        for (int j=i; j<=50; j++) {
            if (edgeTable[i][j]) {
                dp[i] += (history[j]-1);
                nr += history[i]-1;
            }
        }
    }
    return nr;
}

int solve(int k, vector<vector<int>>& edgeTable, vector<int> nodes) {
    int subtrees = 1;
    vector<int> dp1(51, 0);
    vector<int> dp2(51, 0);
    dp2.assign(nodes.begin(), nodes.end());

    for (int i=2; i<=k; i++) {
        if (i % 2) {
            subtrees += nrSubtree(edgeTable, dp1, dp2);
        }
        else {
            subtrees += nrSubtree(edgeTable, dp2, dp1);
        }
    }
    return subtrees;
}

int main() {
    int n, k;
    cin >> n >> k;

    int usingNode = 0;
    vector<int> nodes(51, 0);
    vector <vector<int>> edgeTable(51, vector<int>(51, 0));

    for (int i=0; i<n-1 ;i++) {
        int node1, node2;

        cin >> node1 >> node2;

        edgeTable[node1][node2] = 1;
        edgeTable[node2][node1] = 1;

        if (++nodes[node1] == 1) {
            usingNode++;
        }
        if (++nodes[node2] == 1) {
            usingNode++;
        }

        printf("%d %d\n", node1, node2);
    }

    printf("%d\n", usingNode + solve(k, edgeTable, nodes));

    return 0;
}
