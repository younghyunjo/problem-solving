#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    int nr_rope;
    cin >> nr_rope;

    int rope[nr_rope];
    for (int i=0; i<nr_rope; i++) {
        cin >> rope[i];
    }

    sort(rope, rope + nr_rope, greater<int>());

    int max_weight = 0;
    int using_rope = 0;
    int current_weight = rope[0];

    for (int i=1; i<nr_rope; i++) {
        current_weight = rope[i] * (i+1);

        if (current_weight >= max_weight) {
            max_weight = current_weight;
            using_rope++;
        }
    }

    cout << max_weight;

    return 0;
}