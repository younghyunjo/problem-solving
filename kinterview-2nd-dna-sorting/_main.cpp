#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;


#define DNA_LEN 128
#define DNA_NUMBER_DIVIDER 16


struct dna {
    char dna[DNA_LEN+1] = {0,};
    unsigned long long dnaNumber[DNA_LEN/DNA_NUMBER_DIVIDER];
    int a;

    friend bool operator<(struct dna& d1, struct dna& d2) {
        return d1.a < d2.a;
    }

    unsigned operator==(const int _a) {a == _a;};
};

bool dnaNumberComparator(struct dna d1, struct dna d2) {
    for (int i=0; i<DNA_LEN/DNA_NUMBER_DIVIDER; i++) {
        if (d1.dnaNumber[i] < d2.dnaNumber[i]) {
            return true;
        }
    }
    return false;
}

static vector<dna> dnaVector;
static int n;

void dnaToNumber(char* s, unsigned long long *dnaNumber) {
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
        }

//        printf("%s\n", numberString);
        dnaNumber[i] = atoll(numberString);
    }
}

void vectorPrint() {
    for (auto& i : dnaVector) {
        printf("A:%d DNA:%s NUM:%lld\n", i.a, i.dna, i.dnaNumber[0]);
    }
}

void solve(int q, int k) {
    vector<dna>::iterator pos = find(dnaVector.begin(), dnaVector.end(), q);

    printf("A:%d DNA:%s NUM:%lld\n", pos->a, pos->dna, pos->dnaNumber[0]);

}

int main() {
//

    cin >> n;
    for (int i=0; i<n ;i++) {
        int a;
        string dna;
        cin >> dna >> a;
        struct dna dnaTmp;

        strncpy(dnaTmp.dna, dna.c_str(), DNA_LEN);
        dnaTmp.a = a;
        dnaToNumber((char*)dna.c_str(), dnaTmp.dnaNumber);

        dnaVector.push_back(dnaTmp);
    }

    sort(dnaVector.begin(), dnaVector.end());


    //vectorPrint();


    int m;
    for (cin >> m; m ;m--) {
        int q, k;
        cin >> q >> k;
        solve(q, k);
        return 0;
    }





    return 0;
}