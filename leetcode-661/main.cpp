//https://leetcode.com/problems/image-smoother/description/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        row = M.size();
        column = M[0].size();

        matrix = M;
        vector<vector<int>> ret(row, vector<int> (column));
        for (int x=0; x<row; x++) {
            for (int y=0; y<column; y++) {
                ret[x][y] = smoother(x, y);
            }
        }
        return ret;
    };

private:
    vector<vector<int>> matrix;
    int row;
    int column;

    int smoother(int x, int y) {
        int sum = 0;
        int count = 0;

        vector<int> index({-1, 0, 1});
        for (int i=0; i<index.size(); i++) {
            if ((x + index[i] < 0) || (x + index[i] >= row))
                continue;

            for (int j=0; j<index.size(); j++) {
                if ((y + index[j] < 0) || (y + index[j] >= column))
                    continue;

                sum += matrix[x+index[i]][y+index[j]];
                count++;
            }
        }
        return sum / count;
    }
};

int main() {
    vector<vector<int>> matrix({
            vector<int>({2,3,4}),
            vector<int>({5,6,7}),
            vector<int>({8,9,10}),
            vector<int>({11,12,13}),
            vector<int>({14,15,16})
            });

    Solution s;
    auto ret = s.imageSmoother(matrix);

    for (int i=0; i<ret.size(); i++) {
        for (int j=0; j<ret[i].size(); j++) {
            cout << ret[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}