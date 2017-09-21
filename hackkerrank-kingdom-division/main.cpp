//https://www.hackerrank.com/challenges/kingdom-division

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

long long minCandies(vector<int> score) {
    vector<int> candies;
    candies.assign(score.size(), 1);

    for (int i=1; i<score.size(); i++) {
        if (score[i] > score[i-1])
            candies[i] = candies[i-1] +1;
    }

    for (int i=score.size()-2; i>=0; i--) {
        if (score[i] > score[i+1])
            candies[i] = max(candies[i], candies[i+1] +1);
    }

    long long sum = 0;
    for (int i=0; i<score.size(); i++) {
        sum += candies[i];
    }

    return sum;
}

using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> score(n, 0);
    for (int i=0; i<n; i++)
        cin >> score[i];
    printf("%lld", minCandies(score));
    return 0;
}

