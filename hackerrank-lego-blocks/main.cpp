//https://www.hackerrank.com/challenges/lego-blocks/problem

#include <iostream>
#include <vector>

using namespace std;

#define MODULO 1000000007

long long int f[1001] = {0,};

long long int pow(long long int x, int y) {
    long long int ans = 1;
    while (y--) {
        ans = (ans * x) % MODULO;
    }

    return ans;
}

long long int solve(int height, int width) {
    long long int g[1001] = {0,};

    for (int i=1; i<=width; i++) {
        g[i] = pow(f[i], height);
    }


    int h[width+1] = {0,};
    h[1] = 1;
    for (int i=2; i<=width; i++) {
        h[i] = g[i];
        long long int tmp = 0;
        for (int j=1; j<i; j++) {
            tmp = (tmp + h[j] * g[i-j]) % MODULO;
        }
        h[i] = (h[i] - tmp + MODULO) % MODULO;
    }

    return h[width];
}

int main() {
    f[0] = 1;
    for (int i=1; i<=1000; i++) {
        for (int j=1; j<=4; j++) {
            if (i-j >= 0) {
                f[i] = (f[i] + f[i-j]) % MODULO;
            }
        }
    }

    int t;
    for (cin>> t ;t; t--) {
        int n, m;
        cin >> n >> m;
        printf("%lld\n", solve(n, m));
    }

    return 0;
}