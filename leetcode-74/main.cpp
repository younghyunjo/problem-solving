//https://leetcode.com/problems/search-a-2d-matrix/description/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if (row == 0)
            return false;

        int column = matrix[0].size();
        if (column == 0)
            return false;

        int lowY = 0, highY = matrix.size() -1, midY;


        while (lowY <= highY) {
            midY = (lowY + highY) / 2;
            if (matrix[midY][0] <= target && target <= matrix[midY][column-1])
                break;
            else if (matrix[midY][0] > target)
                highY = midY - 1;
            else
                lowY = midY + 1;
        }

        if (lowY > highY) {
            return false;
        }


        int lowX = 0, highX = matrix[0].size() -1, midX;
        while (lowX <= highX) {
            midX = (lowX + highX) / 2;
            if (matrix[midY][midX] > target) {
                highX = midX -1;
            }
            else if (matrix[midY][midX] < target) {
                lowX = midX +1;
            }
            else
                return true;
        }

        return false;
    }
};

int main() {
    Solution s;
    vector<vector<int>> matrix = {{1}, {3}, {5}};
    cout << s.searchMatrix(matrix, 3) << endl;
    return 0;
}