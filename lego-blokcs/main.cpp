//https://www.hackerrank.com/challenges/brick-tiling/problem

#include <iostream>
#include <vector>

using namespace std;


#define MODULO 1000000007

long long int pow(long long int a, int p) {
    long long ans = 1;
    while(p) {
        if (p % 2) ans = ans * a % MODULO;
        a = a * a % MODULO;
        p /= 2;
    }

    return ans;
}

long long int solve(int height, int width) {
    vector<long long int> f(1000+1, 0);
    f[0] = 1;

    for (int i=1; i<=1000; i++)
        for (int j=1; j<=4; j++)
            if (i-j >= 0)
                f[i] = (f[i] + f[i-j]) % MODULO;

    vector<long long int> g(width+1, 0);

    for (int i=1; i<=width; i++) {
        g[i] = pow(f[i], height);
    }

    vector<long long int> h(width+1, 0);

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
    int t;
    for (cin>> t ;t; t--) {
        int n, m;
        cin >> n >> m;
        printf("%lld\n", solve(n, m));
    }

    return 0;
}