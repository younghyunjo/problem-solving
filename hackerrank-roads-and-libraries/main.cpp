//https://www.hackerrank.com/challenges/torque-and-development

#include <bits/stdc++.h>
#include <algorithm>
#include <stack>

using namespace std;

int countCities(const vector<vector<int>>& cityMap, vector<int>& visited, const int startCity) {
    int nrCitiesInCluster = 0;
    stack<int> dfsQueue;

    dfsQueue.push(startCity);

    while(!dfsQueue.empty()) {
        int city = dfsQueue.top();
        dfsQueue.pop();

        if (visited[city])
            continue;

        visited[city] = 1;
        nrCitiesInCluster++;
        for (auto& connectedCity : cityMap[city]) {
            dfsQueue.push(connectedCity);
        }
    }

    return nrCitiesInCluster;
}

long long solve(const vector<vector<int>>& cityMap, const int nrCities, const int costLibrary, const int costRoad) {
    long long sum = 0;
    vector<int> visited(nrCities+1, 0);

    for (int i=1; i<=nrCities; i++) {
        if (visited[i] == 0) {
            int nrCitiesInCluster = countCities(cityMap, visited, i);
            sum += min((nrCitiesInCluster-1)*costRoad + costLibrary, costLibrary*nrCitiesInCluster);
        }
    }

    return sum;
}

int main() {

    int nrTestcase;
    cin >> nrTestcase;

    for (int i=0; i<nrTestcase; i++) {
        int nrRoads;
        int nrCities;
        int costLibrary;
        int costRoad;
        vector<vector<int>> cityMap;

        cin >> nrCities >> nrRoads >> costLibrary >> costRoad;
        cityMap.resize(nrCities+1);

        int city1, city2;
        for (int roadIndex=0; roadIndex<nrRoads; roadIndex++) {
            cin >> city1 >> city2;
            cityMap[city1].push_back(city2);
            cityMap[city2].push_back(city1);
        }
        printf("%lld\n", solve(cityMap, nrCities, costLibrary, costRoad));
    }

    return 0;
}
