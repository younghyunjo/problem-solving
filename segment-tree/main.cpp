#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long init(vector<long long>& a, vector<long long>&tree, int node, int start, int end) {

    if (start == end)
        return tree[node]  = a[start];
    else {
        return tree[node] = init(a, tree, node*2, start, (start+end)/2) + init(a, tree, node*2+1, (start+end)/2+1, end);
    }
}

long long sum(vector<long long>&tree, int node, int start, int end, int left, int right) {
    if (left > end || right < start) {
        return 0;
    }
    else if (left <= start && end <= right) {
        return tree[node];
    }
    else {
        return sum(tree, node*2, start, (start+end)/2, left, right) + sum(tree, node*2+1, (start+end)/2+1, end, left, right);
    }
}

void update(vector<long long>& tree, int node, int start, int end, int index, long long diff) {
    if (index < start || index > end)
        return;

    tree[node] -= diff;
    if (start != end) {
        update(tree, node*2, start, (start+end)/2, index, diff);
        update(tree, node*2+1, (start+end)/2+1, end, index, diff);
    }
}

int main() {
    vector<long long> input = {3, 4, 1, 2, 5};
    int h = ceil(log2(input.size()));
    int treeSize = (1 << (h+1));
    vector<long long> tree(treeSize, 0);
    init(input, tree, 1, 0, input.size()-1);
    cout << sum(tree, 1, 0, input.size()-1, 0, 1) << endl;
    update(tree, 1, 0, input.size()-1, 0, 1);
    cout << sum(tree, 1, 0, input.size()-1, 0, 1) << endl;


    return 0;
}