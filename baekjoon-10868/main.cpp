//https://www.acmicpc.net/status/?user_id=younghyunjo&problem_id=10868&from_mine=1
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class SegmentTree {
private:
    vector<unsigned int> tree;
    vector<unsigned int> array;
    unsigned int init(int node, int arrayIndexStart, int arrayIndexEnd) {
        if (arrayIndexStart == arrayIndexEnd)
            tree[node] = array[arrayIndexStart];
        else {
            int arrayIndexMid = (arrayIndexStart + arrayIndexEnd) / 2;
            init(node*2, arrayIndexStart, arrayIndexMid);
            init(node*2+1, arrayIndexMid+1, arrayIndexEnd);
            if (tree[node*2] < tree[node*2+1])
                tree[node] = tree[node*2];
            else
                tree[node] = tree[node*2+1];

//            tree[node] = min(, );
        }
        return tree[node];
    }

    unsigned int findMin(int node, int nodeIndexStart, int nodeIndexEnd, int arrayIndexStart, int arrayIndexEnd) {
        if (arrayIndexEnd < nodeIndexStart || nodeIndexEnd < arrayIndexStart)
            return 0xffffffff;
        else if (arrayIndexStart <= nodeIndexStart && arrayIndexEnd >= nodeIndexEnd)
            return tree[node];
        else {
            int nodeIndexMid = (nodeIndexStart + nodeIndexEnd) / 2;
            unsigned int left = findMin(node*2, nodeIndexStart, nodeIndexMid, arrayIndexStart, arrayIndexEnd);
            unsigned int right = findMin(node*2+1, nodeIndexMid+1, nodeIndexEnd, arrayIndexStart, arrayIndexEnd);
            if (left < right)
                return left;
            else
                return right;
        }
    }

public:
    SegmentTree(vector<unsigned int>& input) {
        array = input;
        int h = ceil(log2(input.size()));
        int treeSize = pow(2, h+1);
        tree.assign(treeSize, UINT32_MAX);
        init(1, 0, array.size()-1);
    }

    unsigned int min(int from, int to) {
        return findMin(1, 0, array.size()-1, from, to);
    }
};

int main() {
    {
        vector<unsigned int>input = {1, 2, 3};
        SegmentTree st(input);
    }
    int n, m;
    scanf("%d %d", &n, &m);
    vector<unsigned int> input(n, 0);
    for (int i=0; i<n; i++) {
        scanf("%d", &input[i]);
    }
    SegmentTree st(input);

    for (int i=0; i<m; i++) {
        int from, to;
        scanf("%d %d", &from, &to);
        printf("%u\n", st.min(from-1, to-1));
    }

    return 0;
}