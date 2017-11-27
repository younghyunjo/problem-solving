
#include <bits/stdc++.h>

using namespace std;

int minimalPenalty(vector<pair<int, int>>* edges, int from, int to) {
    bool visited[1001][1024];
    memset(visited, false, sizeof(visited));

    queue<pair<int, int>> bfsQueue;
    bfsQueue.push(make_pair(from, 0));

    while (!bfsQueue.empty()) {
        auto& a = bfsQueue.front();
        bfsQueue.pop();

        int node = a.first;
        int cost = a.second;

        for (auto b : edges[node]) {
            if (b.first == node)
                continue;
            int newCost = b.second|cost;
            if (visited[b.first][newCost])
                continue;

            visited[b.first][b.second|cost] = true;
            bfsQueue.push(make_pair(b.first, newCost));
        }
    }

    for (int i=1; i<1024; i++) {
        if (visited[to][i])
            return i;
    }

    return -1;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector <pair<int, int>>edges[1001];


    for (int i=0; i<m; i++) {
        int nodeA, nodeB, cost;
        cin >> nodeA >> nodeB >> cost;
        edges[nodeA].push_back(make_pair(nodeB, cost));
        edges[nodeB].push_back(make_pair(nodeA, cost));
    }

    int from, to;
    cin >> from >> to;

    cout << minimalPenalty(edges, from, to) << endl;

    return 0;
}
