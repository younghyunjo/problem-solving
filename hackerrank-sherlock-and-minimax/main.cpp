#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define inrange(start, end, num) ((start) <= (num) && (num) <= (end))

int calculate_min(int m, vector<int> a) {

    unsigned int k;
    unsigned min = 0xffffffff;
    for (int i = 0; i < a.size(); i++) {
        k = abs(m - a[i]);
        min = k < min ? k : min;
    }

    return min;
}

int inRange(int p, int q, int mid) {
    if (mid >= p && mid <= q)
        return 1;
    return 0;
}

int main() {
    int n;
    cin >> n;

    int input;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        cin >> input;
        a.push_back(input);
    }
    sort(a.begin(), a.end());

    int p, q;
    cin >> p >> q;

    unsigned int distance = 0;
    unsigned int m, max_distance = 0;

    if (n > 1) {
        vector<int> tmp;
        for (int i=1; i<n-1; i++) {
            int mid = (a[i] - a[i-1])/2;
            if (inRange(p, q, mid)) {
                tmp.push_back((mid));
            }

            mid = (a[i+1] - a[i])/2;
            if (inRange(p, q, mid)) {
                tmp.push_back((mid));
            }
        }

        tmp.push_back(p);
        tmp.push_back(q);
        sort(tmp.begin(), tmp.end());

        int best = -1;
        int best_value;

        for(int j=0; j<tmp.size(); j++) {
            int distance = 2147483657;
            int tmp_distance = 0;
            for (int i=0; i<a.size(); i++) {
                tmp_distance = abs(a[i] - tmp[j]);
                if (tmp_distance < distance) {
                    distance = tmp_distance;
                }
            }

            if ( distance > best ) {
                best = distance;
                best_value = tmp[j];
            }
        }
    }
    else {

    }



    return 0;
}
