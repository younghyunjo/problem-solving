//https://www.hackerrank.com/challenges/journey-to-the-moon?h_r=next-challenge&h_v=zen

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <ctime>
#include <cassert>
#include <stack>

using namespace std; // }}}

int countSameCountry(vector<vector<int>> pairs, vector<int>& visited, int start) {
    int count = 0;

    queue<int> bfsQueue;
    bfsQueue.push(start);

    while (!bfsQueue.empty()) {
        int astronaut = bfsQueue.front();
        bfsQueue.pop();

        if (visited[astronaut])
            continue;

        visited[astronaut] = 1;
        count++;

        for (auto& i : pairs[astronaut]) {
            bfsQueue.push(i);
        }
    }

    return count;
}

long long solve(const int N, const vector<vector<int>> pairs) {
    vector<int> visited(N, 0);
    vector<int> sameCounties;
    long long numberOfsingleAstronauts = 0;


    for (int i=0; i<N; i++) {
        if (visited[i])
            continue;

        if (pairs[i].size() == 0) {
            visited[i] = true;
            numberOfsingleAstronauts++;
            continue;
        }

        int numberOfSameCountry = countSameCountry(pairs, visited, i);
        sameCounties.push_back(numberOfSameCountry);
    }

    long long ret = numberOfsingleAstronauts * (numberOfsingleAstronauts-1)/2;
    for (int i=0; i<sameCounties.size(); i++) {
        ret += numberOfsingleAstronauts * sameCounties[i];

        int j=i+1;
        while (j < sameCounties.size()) {
            ret += sameCounties[i] * sameCounties[j];
            j++;
        }
    }

    return ret;
}

int main()
{
    int N, I;
    cin >> N >> I;
    vector<vector<int> > pairs(N);
    for (int i = 0; i < I; ++i) {
        int a, b;
        cin >> a >> b;
        pairs[a].push_back(b);
        pairs[b].push_back(a);
    }

    long long result = 0;

    printf("%lld\n", solve(N, pairs));

    return 0;
}
