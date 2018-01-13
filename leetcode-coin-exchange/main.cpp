//https://leetcode.com/problems/coin-change/description/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int INTMAX = amount + 1;
        vector<int> cache(amount + 1, INTMAX);
        cache[0] = 0;

        for (int i=1; i<=amount; i++) {
            for (auto& j : coins) {
                if (j > i)
                    continue;
                cache[i] = min(cache[i], cache[i - j] + 1);
            }
        }

        if (cache[amount] >= INTMAX)
            return -1;
        return cache[amount];

    }
};

int main() {
    Solution s;
    vector<int> c = {2, 5};
    cout << s.coinChange(c,  4) << endl;
    return 0;
}