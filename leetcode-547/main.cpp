//https://leetcode.com/problems/friend-circles/description/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        int hits[n] = {0,};

        int nrCircle = 0;
        for (int i=0; i<n ;i++) {
            if (hits[i] == 1)
                continue;
            dfs(i, M, hits);
            nrCircle++;

        }


        return nrCircle;
    }

private:
    void dfs(int index, vector<vector<int>>&M, int* hits) {
        for (int j=0; j<M.size(); j++) {
            if (M[index][j] == 1 && hits[j] == 0) {
                hits[j] = 1;
                dfs(j, M, hits);
            }
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}