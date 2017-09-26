//https://www.hackerrank.com/challenges/time-conversion

#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    int hour, minute, second;
    char flag;
    scanf("%02d:%02d:%02d%cM", &hour, &minute, &second, &flag);

    if (hour == 12) {
        if (flag == 'A')
            hour = 0;
    }
    else if (flag == 'P') {
        hour += 12;
        if (hour ==24)
            hour = 0;
    }

    printf("%02d:%02d:%02d\n", hour, minute, second);


    return 0;
}
