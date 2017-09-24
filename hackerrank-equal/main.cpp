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

int equal(vector<int> colleague) {
    sort(colleague.begin(), colleague.end());

    int mininumChocolate = *min_element(colleague.begin(), colleague.end());
    int sum = 0;
    int ret = INT_MAX;

    for (int j=0; j<5; j++) {
        sum = 0;
        for (int i = 0; i < colleague.size(); i++) {
            int tmp = colleague[i] - mininumChocolate + j;
            sum += (tmp/5) + (tmp%5)/2 + (tmp%5)%2;
        }

        ret = min(ret, sum);
    }

    return ret;
}

int main() {
    int nrTestcase;
    cin >> nrTestcase;

    for (int i=0; i<nrTestcase; i++) {
        int nrColleauge;
        cin >> nrColleauge;
        vector<int> colleauge(nrColleauge);

        for (int j=0; j<nrColleauge; j++) {
            cin >> colleauge[j];
        }

        cout << equal(colleauge) << endl;
    }
    return 0;
}
