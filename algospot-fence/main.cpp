#include <iostream>
#include <cstring>

using namespace std;

int nrFence;
int H[20000];

int fence(int left, int right) {
    if (left == right)
        return H[left];

    int mid = (left + right) / 2;
    int ret = max(fence(left, mid), fence(mid+1, right));

    int lo = mid, hi = mid;
    int height = H[mid];

    while (left != lo || hi != right) {
        if (hi != right && (lo == left || H[lo-1] < H[hi+1])) {
            height = min(height, H[++hi]);
        }
        else if (lo != left) {
            height = min(height, H[--lo]);
        }
        else {
            break;
        }

        ret = max(ret, (hi - lo + 1) * height);
    }

    return ret;
}

int main() {
    int nrTestcase;
    cin >> nrTestcase;
    for (int i=0; i<nrTestcase; i++) {
        memset(H, 0, sizeof(H));
        cin >> nrFence;
        for (int j=0; j<nrFence; j++) {
            cin >> H[j];
        }

        int ret = fence(0, nrFence-1);
        cout << ret <<endl;
    }

    return 0;
}

