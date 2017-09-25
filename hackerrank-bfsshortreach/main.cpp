//https://www.hackerrank.com/challenges/bfsshortreach

#include <bits/stdc++.h>

using namespace std;

vector<int> bfs(vector<vector<int>>& graph, int start) {
    vector<int> length(graph.size(), -1);
    queue<pair<int, int>> bfsQueue;

    bfsQueue.push(make_pair(start, 0));

    while (!bfsQueue.empty()) {

        pair<int, int> node = bfsQueue.front();
        bfsQueue.pop();

        if (length[node.first] != -1) {
            continue;
        }

        length[node.first] = node.second;

        for (auto& i : graph[node.first]) {
            bfsQueue.push(make_pair(i, node.second+1));
        }
    }

    return length;
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int n, m;
        cin >> n >> m;

        vector<vector<int>> graph(n+1);


        for(int a1 = 0; a1 < m; a1++){
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int s;
        cin >> s;

        vector<int> ret = bfs(graph, s);
        for (int i=1; i<=n; i++) {
            if (ret[i] == 0)
                continue;
            if (ret[i] != -1)
                printf("%d ", ret[i] * 6);
            else
                printf("%d ", ret[i]);
        }
        printf("\n");

    }
    return 0;
}
