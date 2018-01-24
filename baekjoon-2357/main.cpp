//https://www.acmicpc.net/problem/2357
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int minimumTreeCompare(int a, int b) {
    return a < b ? a : b;
}

int maximumTreeCompare(int a, int b) {
    return a > b ? a : b;
}

class SegmentTree {
private:
    int n;
    vector<pair<int, int>> tree;

    void init(vector<int>& array, int node, int arrStart, int arrEnd) {
        if (arrStart == arrEnd) {
            tree[node].first = array[arrStart];
            tree[node].second = array[arrStart];
        }
        else {
            int arrMid = (arrStart + arrEnd) / 2;
            init(array, node*2, arrStart, arrMid);
            init(array, node*2+1, arrMid + 1, arrEnd);
            tree[node].first = minimumTreeCompare(tree[node*2].first, tree[node*2+1].first);
            tree[node].second = maximumTreeCompare(tree[node*2].second, tree[node*2+1].second);
        }
    }

    pair<int, int> findValue(int node, int nodeStart, int nodeEnd, int from, int to) {
        if (to < nodeStart || nodeEnd < from ) {
            return make_pair(INT32_MAX, 0);
        }
        else if (from <= nodeStart && nodeEnd<= to){
            return tree[node];
        }
        else {
            int nodeMid = (nodeStart + nodeEnd) / 2;
            pair<int, int> left = findValue(node*2, nodeStart, nodeMid, from, to);
            pair<int, int> right = findValue(node*2+1, nodeMid+1, nodeEnd, from, to);

            int minimum = left.first < right.first ? left.first : right.first;
            int maximum = left.second > right.second ? left.second : right.second;
            return make_pair(minimum, maximum);
        }
    }

public:
    SegmentTree(vector<int> input) {
        int h = ceil(log2(input.size()));
        int treeSize = (1 << (h+1));
        n = input.size();
        tree.assign(treeSize, make_pair(INT32_MAX, 0));

        init(input, 1, 0, n-1);
    }

    pair<int, int> minMaxValue(int from, int to) {
        return findValue(1, 0, n-1, from, to);
    }

};

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> input(n, 0);
    for (int i=0; i<n; i++) {
        scanf("%d", &input[i]);
    }

    SegmentTree st(input);
    for (int i=0; i<m ;i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        pair<int, int> ret = st.minMaxValue(a-1, b-1);
        printf("%d %d\n", ret.first, ret.second);
    }
    return 0;
}