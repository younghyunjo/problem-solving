//https://leetcode.com/problems/maximal-square/description/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        if (row == 0)
            return 0;

        int column = matrix[0].size();
        int answer = 0;

        vector<vector <int>> p(row, vector<int>(column, 0));

        for (int i=0; i<row; i++) {
            answer = max(answer, p[i][0] = matrix[i][0] - '0');
        }

        for (int j=1; j<column; j++) {
            answer = max(answer, p[0][j] = matrix[0][j] - '0');
        }

        for (int i=1; i<row; i++) {
            for (int j=1; j<column; j++) {
                if (matrix[i][j] == '0')
                    continue;

                p[i][j] = min(p[i][j-1], min(p[i-1][j-1], p[i-1][j])) + 1;
                answer = max(answer, p[i][j]);
            }
        }

        return answer * answer;
    }
};

int main() {
    vector<vector <char>> m = {{'1', '1', '1'},
                               {'0', '1', '1'},
                               {'0', '1', '1'}};

    Solution s;
    cout << s.maximalSquare(m) << endl;

    return 0;
}