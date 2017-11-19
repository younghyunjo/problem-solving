#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <numeric>
using namespace std;

#define DNA_LEN 128
#define DNA_NUMBER_DIVIDER 16

static int n;

struct dnaTable {
    string dna;
    unsigned long long int dnaNumber[DNA_LEN/DNA_NUMBER_DIVIDER];
    uint8_t nrOrder[100];
    unsigned operator==(const unsigned long long int _dnaNumber[8]) {
        return memcmp(dnaNumber, _dnaNumber, sizeof(dnaNumber)) == 0;
    }
};

vector<struct dnaTable> dtable;

void dnaStringToNumber(char* s, unsigned long long int *dnaNumber) {
    if (strlen(s) != DNA_LEN) {
        printf("[ERR] wrong length:%ld\n", strlen(s));
        return;
    }

    char numberString[DNA_NUMBER_DIVIDER+1] = {0,};

    for (int i=0; i<DNA_LEN/DNA_NUMBER_DIVIDER; i++) {
        char* dividedDna = s+i*DNA_NUMBER_DIVIDER;
        for (int j=0; j<DNA_NUMBER_DIVIDER; j++) {
            if (dividedDna[j] == 'G') {
                numberString[j] = '4';
            } else
                numberString[j] = (10 - (dividedDna[j] % 10)) + '0';
            //C -> 3, G->4, A->5, T->6
        }

        dnaNumber[i] = atoll(numberString);
    }
}

bool candidateComprator(pair<int, int>& c1, pair<int, int>& c2) {
    if (c1.first != c2.first) {
        return c1.first > c2.first;
    }
    else {
        struct dnaTable d1 = dtable[c1.second];
        struct dnaTable d2 = dtable[c2.second];

        for (int i=0; i<DNA_LEN/DNA_NUMBER_DIVIDER; i++) {
            if (d1.dnaNumber[i] < d2.dnaNumber[i]) {
                return true;
            } else
                return false;
        }
        return true;
    }
}

void solve(int q, int k) {
    vector<pair<int, int>> candidate;
    for(int i=0; i<dtable.size(); i++) {
        int sum = accumulate(&dtable[i].nrOrder[q], &dtable[i].nrOrder[100], 0);
        candidate.push_back(make_pair(sum, i));
    }

    sort(candidate.begin(), candidate.end(), candidateComprator);

    printf("%d\n", min(k, (int)candidate.size()));
    for (int i=0; i<candidate.size() && i < k; i++) {
        printf("%d %s\n", candidate[i].first, dtable[candidate[i].second].dna.c_str());
    }
}

void insertDnaTable(int a, string dna) {
    unsigned long long int dnaNumber[DNA_LEN/DNA_NUMBER_DIVIDER];
    dnaStringToNumber((char*)dna.c_str(), dnaNumber);
    vector<struct dnaTable>::iterator pos;
    pos = find(dtable.begin(), dtable.end(), dnaNumber);
    if (pos == dtable.end()) {
        struct dnaTable d;
        memcpy(d.dnaNumber, dnaNumber, sizeof(d.dnaNumber));
        memset(d.nrOrder, 0, sizeof(d.nrOrder));
        d.dna = dna;
        d.nrOrder[a] = 1;
        dtable.push_back(d);
    }
    else {
        pos->nrOrder[a]++;
    }
}

int main() {

    cin >> n;
    for (int i=0; i<n ;i++) {
        int a;
        string dna;
        cin >> dna >> a;
        insertDnaTable(a, dna);
    }

    int m;
    for (cin >> m; m ;m--) {
        int q, k;
        cin >> q >> k;
        solve(q, k);
    }

    return 0;
}
