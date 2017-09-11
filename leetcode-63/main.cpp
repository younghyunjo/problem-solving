//https://leetcode.com/problems/unique-paths-ii/description/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int y = obstacleGrid.size();
        int x = obstacleGrid[0].size();
        vector<vector<int>> cache(y+1, vector<int>(x+1, 0));

        cache[0][1] = 1;

        for (int i=1; i<=y; i++) {
            for (int j=1; j<=x; j++) {
                if (obstacleGrid[i-1][j-1] != 1)
                    cache[i][j] = cache[i-1][j] + cache[i][j-1];
            }
        }
        return cache[y][x];
    }
};

int main() {
    Solution s;
    vector<vector<int>> obstacleGrid = {
            {0, 0, 0},
            {0, 1, 0},
            {0, 0, 0}
    };
    cout << s.uniquePathsWithObstacles(obstacleGrid) << endl;
    return 0;
}