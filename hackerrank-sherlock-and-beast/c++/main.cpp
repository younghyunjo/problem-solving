#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string find_decent_number(int digit)
{
    string decent_number("-1");
    if (digit < 2) {
        return decent_number;
    }

    for (int i = digit; i >= 0; i--) {
        if (i % 3 == 0 && (digit-i) % 5 == 0) {
            decent_number = string(i, '5');
            if (digit-i) {
                decent_number += string(digit-i, '3');
            }
            break;
        }
    }
    return decent_number;
}

int main()
{
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        cout << find_decent_number(n) <<endl;
    }

    return 0;
}
