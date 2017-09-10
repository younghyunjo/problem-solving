//https://leetcode.com/problems/unique-paths-ii/description/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int y = obstacleGrid.size();
        int x = obstacleGrid[0].size();
        vector<vector<int>> cache(y, vector<int>(x, 0));

        for (int i=0; i<y; i++) {
            if (obstacleGrid[i][0] == 1)
                break;
            cache[i][0] = 1;
        }

        for (int j=0; j<x; j++) {
            if (obstacleGrid[0][j] == 1)
                break;
            cache[0][j] = 1;
        }

        for (int i=1; i<y; i++) {
            for (int j=1; j<x; j++) {
                if (obstacleGrid[i][j] == 1)
                    cache[i][j] = 0;
                else
                    cache[i][j] = cache[i-1][j] + cache[i][j-1];
            }
        }
        return cache[y-1][x-1];
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