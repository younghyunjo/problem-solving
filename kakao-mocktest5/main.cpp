#include<vector>
#include <iostream>

using namespace std;

static const int column = 4;
static int row = 0;
static vector<vector<int>> _land;
static vector<vector<int>> cache;

int maxLand(int currentRow, int prevColumn) {
    int landSize = 0;

    if (currentRow >= row)
        return 0;

    int& ret = cache[currentRow][prevColumn];
    if (ret != -1) {
        return ret;
    }

    for (int i=0; i<column; i++) {
        if (i == prevColumn)
            continue;

        landSize = max(landSize, maxLand(currentRow + 1, i) + _land[currentRow][i]);
    }

    ret = landSize;
    return landSize;
}

int solution(vector<vector<int> > land)
{
    row = land.size();
    _land = land;
    cache.assign(row, vector<int>(5, -1));

    return maxLand(0, 4);
}

int main() {
    vector<vector<int>> l1 = {
            {1, 2, 3, 5},
            {5, 6, 7, 8},
            {4, 3, 2, 1}
    };

    cout << solution(l1) << endl;

    return 0;
}