#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class SegmentTree {
private:
    int n;
    vector<long long> tree;
    vector<long long> array;

    long long init(vector<long long>& a, int node, int startIndex, int endIndex) {
        if (startIndex == endIndex) {
            tree[node] = a[startIndex];
        }
        else {
            int midIndex = (startIndex + endIndex) / 2;
            tree[node] = init(a, node*2, startIndex, midIndex) + init(a, node*2+1, midIndex+1, endIndex);
        }
        return tree[node];
    }

    long long aggregating (int node, int arrIndexStart, int arrIndexEnd, int nodeIndexStart, int nodeIndexEnd) {
        if (arrIndexEnd < nodeIndexStart || nodeIndexEnd < arrIndexStart)
            return 0;
        else if (arrIndexStart <= nodeIndexStart && nodeIndexEnd <= arrIndexEnd) {
            return tree[node];
        }
        else {
            int nodeIndexMid = (nodeIndexStart + nodeIndexEnd) / 2;
            return aggregating(node*2, arrIndexStart, arrIndexEnd, nodeIndexStart, nodeIndexMid) + aggregating(node*2+1, arrIndexStart, arrIndexEnd, nodeIndexMid+1, nodeIndexEnd);
        }
    }

    void updating(int node, int nodeIndexStart, int nodeIndexEnd, int updateIndex, int diff) {
        if (updateIndex < nodeIndexStart || updateIndex > nodeIndexEnd) {
            return;
        }

        tree[node] += diff;
        if (nodeIndexStart != nodeIndexEnd) {
            int nodeIndexMid = (nodeIndexStart + nodeIndexEnd) / 2;
            updating(node*2, nodeIndexStart, nodeIndexMid, updateIndex, diff);
            updating(node*2 + 1, nodeIndexMid + 1, nodeIndexEnd, updateIndex, diff);
        }
    }

public:
    SegmentTree(vector<long long>& a) {
        n = a.size();
        array = a;
        int h = ceil(log2(a.size()));
        int treeSize = pow(2, h+1);
        tree.assign(treeSize, 0);
        init(a, 1, 0, n-1);
    }

    long long sum(int from, int to) {
        return aggregating(1, from, to, 0, n-1);
    }

    void update(int arrIndex, int newValue) {
        int diff = newValue - array[arrIndex];
        array[arrIndex] = newValue;
        updating(1, 0, n-1, arrIndex, diff);
    }

};

int main() {

    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    vector<long long> a(n, 0);
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }

    SegmentTree st(a);

    for (int i=0; i<m+k; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if (a == 1) {
            st.update(b-1,c);
        }
        else {
            printf("%lld\n", st.sum(b-1, c-1));
        }
    }

    return 0;
}