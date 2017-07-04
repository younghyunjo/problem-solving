#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int nr_coin, money;
    cin >> nr_coin >> money;

    int coins[nr_coin];
    for (int i=0; i<nr_coin; i++) {
        cin >> coins[i];
    }

    int coins_index = nr_coin-1;
    int nr_using_coins = 0;

    while (money) {
        nr_using_coins += (money / coins[coins_index]);
        money %= coins[coins_index];
        coins_index--;
    }

    cout << nr_using_coins;

    return 0;
}